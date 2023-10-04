/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:56:40 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/04 19:24:02 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	limit_range(t_rgb *rgb)
{
	if (rgb->red > 255)
		(*rgb).red = 255;
	else if (rgb->red < 0)
		(*rgb).red = 0;
	if (rgb->green > 255)
		(*rgb).green = 255;
	else if (rgb->green < 0)
		(*rgb).green = 0;
	if (rgb->blue > 255)
		(*rgb).blue = 255;
	else if (rgb->blue < 0)
		(*rgb).blue = 0;
}

/*!
 * @brief
 	Perform lighting calculations for a scene and an intersection.
 * @param scene
 	Pointer to the scene.
 * @param isec
 	Pointer to the intersection structure.
 */
static void	lighting(t_scene *scene, t_intersec *isec)
{
	t_lighting			l;
	t_camera			*cam;
	t_ambient_lightning	*al;
	t_light				*lg;

	cam = t_scene_get_camera(scene);
	al = t_scene_get_ambient_light(scene);
	lg = t_scene_get_light(scene);

	l.ambient = v_mult(rgb_to_v3(*al->rgb), al->ratio);
	l.light = v_unit(v_sub_vec((*lg->origin), isec->point));
	l.dfactor = fmax(0.0, v_dot_product(isec->normal, l.light));
	l.diffuse = v_mult(rgb_to_v3(*al->rgb), l.dfactor * 0.6);
	l.viewdir = v_unit(v_sub_vec((*cam->origin), isec->point));
	l.reflect = v_unit(v_sub_vec(v_mult(isec->normal, (2.0 * v_dot_product(l.light, isec->normal))), l.light));
	l.sfactor = pow(fmax(v_dot_product(l.viewdir, l.reflect), 0.0), 32);
	l.specular = v_mult(rgb_to_v3(*al->rgb), l.sfactor * 0.5);
	l.color = v_add_vec(v_add_vec(l.ambient, l.diffuse), l.specular);
	isec->color = v3_to_rgb(v_mult_vec(l.color, rgb_to_v3(isec->color)));
	limit_range(&isec->color);
}

/*!
 * @brief
 	Calculate the ray direction for a given pixel on the screen.
 * @param ray
 	Pointer to the ray structure to store the calculated ray.
 * @param cam
 	Pointer to the camera.
 * @param x
 	X-coordinate of the pixel.
 * @param y
 	Y-coordinate of the pixel.
 */
static void	ray_for_pixel(t_ray *ray, t_camera *cam, size_t x, size_t y)
{
	t_texture_coords    map;

	map.u = (2 * ((x + 0.5) / (double)WIN_WIDTH) - 1) * (double)(WIN_WIDTH / (double)WIN_HEIGHT);
	map.v = (1 - 2 * (y + 0.5) / (double)WIN_HEIGHT);
	ray->origin = (*cam->origin);
    ray->direction = v_unit((t_v3){
        map.u * cam->u.x + map.v * cam->v.x - cam->d * cam->w.x,
        map.u * cam->u.y + map.v * cam->v.y - cam->d * cam->w.y,
        map.u * cam->u.z + map.v * cam->v.z - cam->d * cam->w.z
    });
}

/*!
 * @brief
 	Perform raycasting to determine the color of a pixel in the scene.
 * @param scene
 	Pointer to the scene.
 * @param cam
 	Pointer to the camera.
 * @param x
 	X-coordinate of the pixel.
 * @param y
 	Y-coordinate of the pixel.
 * @return
 	The color of the pixel as an integer.
 */
int	raycaster(t_scene *scene, t_camera *cam, int x, int y)
{
	t_ray		ray;
	t_intersec	isec;

	ray_for_pixel(&ray, cam, x, y);
	intersections(scene, ray, &isec);
	if (isec.has_intersec)
		lighting(scene, &isec);
	return (rgb_to_int(&isec.color));
}
