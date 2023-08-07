/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:47:30 by anvannin          #+#    #+#             */
/*   Updated: 2023/08/07 21:15:57 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
