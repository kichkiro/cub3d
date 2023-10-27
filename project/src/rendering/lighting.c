/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:27:21 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/27 20:30:03 by anvannin         ###   ########.fr       */
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

static bool	shadow(t_scene *scene, t_ray *ray, double len, t_intersec *isec)
{
	isec->has_intersec = false;
	isec->nearest = INFINITY;
	isec->min = EPSILON;
	isec->max = INFINITY;
	t_scene_set_to_head(&scene);
	while (scene)
	{
		if (scene->type == SPHERE)
			intersec_sphere(ray, (t_sphere *)scene->data, &isec);
		else if (scene->type == PLANE)
			intersec_plane(ray, (t_plane *)scene->data, &isec);
		else if (scene->type == CYLINDER)
			intersec_cylinder(ray, (t_cylinder *)scene->data, &isec);
		if (isec->has_intersec && isec->nearest < len)
			return (true);
		scene = scene->next;
	}
	return (false);
}

static void	render_object(t_scene *s, t_lighting l, t_intersec *i, t_light *lg)
{
	t_camera			*cam;
	t_ambient_lightning	*al;

	cam = t_scene_get_camera(s);
	al = t_scene_get_ambient_light(s);
	l.light = v_unit(v_sub_vec((*lg->origin), i->point));
	l.dfactor = fmax(0.0, v_dot_product(i->normal, l.light));
	l.diffuse = v_mult(rgb_to_v3(*al->rgb), l.dfactor * 0.6);
	l.viewdir = v_unit(v_sub_vec((*cam->origin), i->point));
	l.reflect = v_unit(v_sub_vec(v_mult(i->normal, (2.0
						* v_dot_product(l.light, i->normal))), l.light));
	l.sfactor = pow(fmax(v_dot_product(l.viewdir, l.reflect), 0.0), 32);
	l.specular = v_mult(rgb_to_v3(*al->rgb), l.sfactor * 0.5);
	l.color = v_add_vec(v_add_vec(l.ambient, l.diffuse), l.specular);
	i->color = v3_to_rgb(v_mult_vec(l.color, rgb_to_v3(i->color)));
	limit_range(&i->color);
}

/*!
 * @brief
 	Perform lighting calculations for a scene and an intersection.
 * @param scene
 	Pointer to the scene.
 * @param isec
 	Pointer to the intersection structure.
 */
void	lighting(t_scene *scene, t_intersec *isec)
{
	t_lighting			l;
	t_ambient_lightning	*al;
	t_light				*lg;

	al = t_scene_get_ambient_light(scene);
	lg = t_scene_get_light(scene);
	l.ambient = v_mult(rgb_to_v3(*al->rgb), al->ratio);
	l.shadow_ray.origin = v_add_vec(isec->point, v_mult(isec->normal, EPSILON));
	l.shadow_ray.direction = v_sub_vec(*lg->origin, isec->point);
	l.len = v_module(l.shadow_ray.direction);
	l.shadow_ray.direction = v_unit(l.shadow_ray.direction);
	if (shadow(scene, &l.shadow_ray, l.len, isec))
		isec->color = v3_to_rgb(v_mult_vec(l.ambient, rgb_to_v3(isec->color)));
	else
		render_object(scene, l, isec, lg);
}
