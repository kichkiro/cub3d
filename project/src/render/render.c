/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:40:50 by anvannin          #+#    #+#             */
/*   Updated: 2023/08/07 20:50:51 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render_sky_gradient(t_mlx *mlx, int win_x, int win_y)
{
	int		blend_value;
	double	t;

	t = (double)win_y / ((double)WIN_HEIGHT - 1);
	blend_value = (int)(t * 255.999);
	my_pixel_put(mlx->img, win_x, win_y,
		rgb_to_int2(blend_value, 255, blend_value));
}

static void	render_center_cross(t_mlx *mlx)
{
	int	y;
	int	i;

	i = -1;
	my_pixel_put(mlx->img, WIN_WIDTH / 2, WIN_HEIGHT / 2, HEX_WHITE);
	while (++i < 5)
	{
		my_pixel_put(mlx->img, WIN_WIDTH / 2, WIN_HEIGHT / 2 + i, HEX_WHITE);
		my_pixel_put(mlx->img, WIN_WIDTH / 2, WIN_HEIGHT / 2 - i, HEX_WHITE);
		my_pixel_put(mlx->img, WIN_WIDTH / 2 + i, WIN_HEIGHT / 2, HEX_WHITE);
		my_pixel_put(mlx->img, WIN_WIDTH / 2 - i, WIN_HEIGHT / 2, HEX_WHITE);
	}
}

void	render(t_mlx *mlx, t_scene *scene)
{
	render_sphere(mlx, scene);
	render_center_cross(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	window_labels(mlx);
}
