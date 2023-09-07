/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:47:30 by anvannin          #+#    #+#             */
/*   Updated: 2023/09/03 20:34:57 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*!
 * @brief 
	Get the sphere from a scene.
	This function searches for a sphere in a linked list of scene objects and 
	returns a pointer to it if found.
 * @param scene 
	A pointer to the scene containing objects.
 * @return 
	A pointer to the found sphere if it exists, otherwise NULL.
 */
static t_sphere	*get_sphere(t_scene *scene)
{
	t_sphere	*sphere;
	bool		found;

	while (scene->next)
	{
		if (scene->id == SPHERE)
		{
			found = true;
			break ;
		}
		scene = scene->next;
	}
	if (!found)
		return (NULL);
	sphere = ((t_sphere *)scene->data);
	t_scene_set_to_head(&scene);
	return (sphere);
}

/*!
 * @brief 
	Determine if a point on the window hits a sphere.
	This function checks if a point on the screen, specified by its x and y 
	coordinates, intersects with a given sphere. 
	It calculates the boundaries of the sphere on the screen and checks if the 
	point falls within those boundaries.
 * @param sphere 
	A pointer to the sphere to be checked.
 * @param win_x 
	The x-coordinate of the point on the screen.
 * @param win_y 
	The y-coordinate of the point on the screen.
 * @return 
	True if the point hits the sphere, false otherwise.
 */
static bool	hit_sphere(t_sphere *sphere, int win_x, int win_y)
{
	t_coords	*coords;
	int			left;
	int			right;
	int			top;
	int			bottom;

	coords = sphere->coords;
	left = (int)(coords->x - sphere->diameter / 2) + WIN_WIDTH / 2;
	right = (int)(coords->x + sphere->diameter / 2) + WIN_WIDTH / 2;
	top = (int)(coords->y - sphere->diameter / 2) + WIN_HEIGHT / 2;
	bottom = (int)(coords->y + sphere->diameter / 2) + WIN_HEIGHT / 2;
	if ((win_x >= left && win_x <= right && win_y >= top && win_y <= bottom))
		return (true);
	return (false);
}

/*!
 * @brief 
	Render a sphere on the screen.
	This function renders a sphere on the screen by checking each pixel and 
	determining if it intersects with the sphere.
	If a pixel hits the sphere, its color is set to  the sphere's RGB color; 
	otherwise, it renders a sky gradient color.
 * @param mlx 
	A pointer to the mlx structure used for rendering.
 * @param scene 
	A pointer to the scene containing objects.
 */
void	render_sphere(t_mlx *mlx, t_scene *scene)
{
	t_sphere	*sphere;
	int			win_y;
	int			win_x;

	while (scene->next)
	{
		if (scene->id == SPHERE)
			break ;
		scene = scene->next;
	}
	sphere = ((t_sphere *)scene->data);
	log_sphere(sphere);
	win_y = -1;
	while (++win_y < WIN_HEIGHT)
	{
		win_x = -1;
		while (++win_x < WIN_WIDTH)
		{
			if (hit_sphere(sphere, win_x, win_y))
				my_pixel_put(mlx->img, win_x, win_y, rgb_to_int(sphere->rgb));
			else
				render_sky_gradient(mlx, win_x, win_y);
		}
	}
}
