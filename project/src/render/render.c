/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:40:50 by anvannin          #+#    #+#             */
/*   Updated: 2023/08/02 20:34:22 by anvannin         ###   ########.fr       */
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

// (x−Cx)2+(y−Cy)2+(z−Cz)2=r2
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

	int left = (int)(coords->x - sphere->diameter / 2);
	int right = (int)(coords->x + sphere->diameter / 2);
	int top = (int)(coords->y - sphere->diameter / 2);
	int bottom = (int)(coords->y + sphere->diameter / 2);
	printf("left: %d\tright: %d\ttop: %d\tbottom: %d\n", left, right, top, bottom);

	int		win_y;
	int		win_x;

	int centery = WIN_HEIGHT / 2;
	int centerx = WIN_WIDTH / 2;

	win_y = -1;
	while (++win_y < WIN_HEIGHT)
	{
		win_x = -1;
		while (++win_x < WIN_WIDTH)
		{
			float dx = win_x - coords->x;
			float dy = win_y - coords->y;
			float distance = sqrt(dx * dx + dy * dy);

			float dx2 = win_x - centerx;
			float dy2 = win_y - centery;

			dx += dx2;
			dy += dy2;

			if (win_x >= left && win_x <= right && win_y >= top && win_y <= bottom)
				if (distance <= sphere->diameter / 2)
					my_pixel_put(mlx->img, win_x, win_y, rgb_to_int(sphere->rgb));
		}
	}
}

void	render(t_mlx *mlx, t_scene *scene)
{
	render_gradient_sky(mlx, scene);
	render_sphere(mlx, scene);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	window_labels(mlx);
}
