/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:40:50 by anvannin          #+#    #+#             */
/*   Updated: 2023/08/01 20:32:04 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	render_gradient_sky(t_mlx *mlx, t_scene *scene)
{
	int		win_y;
	int		win_x;
	int		blend_value;
	double	t;

	win_y = -1;
	while (++win_y < WIN_HEIGHT)
	{
		win_x = -1;
		while (++win_x < WIN_WIDTH)
		{
			t = (double)win_y / ((double)WIN_HEIGHT - 1);
			blend_value = (int)(t * 255.999);
			my_pixel_put(mlx->img, win_x, win_y,
				rgb_to_int2(blend_value, 255, blend_value));
		}
	}
}

static void	render_sphere(t_mlx *mlx, t_scene *scene)
{
	t_sphere	*sphere;
	t_coords	*coords;

	while (scene->next)
	{
		if (scene->id == SPHERE)
			break ;
		scene = scene->next;
	}
	sphere = ((t_sphere *)scene->data);
	t_scene_set_to_head(&scene);
	coords = sphere->coords;

	printf("x: %f\ty: %f\tz: %f\n", coords->x, coords->y, coords->z);
	printf("radius: %f\n", sphere->diameter / 2);
	printf("color: %d\n", rgb_to_int(sphere->rgb));
}

void	render(t_mlx *mlx, t_scene *scene)
{
	render_gradient_sky(mlx, scene);
	render_sphere(mlx, scene);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	window_labels(mlx);
}
