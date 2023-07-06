/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:40:10 by anvannin          #+#    #+#             */
/*   Updated: 2023/07/06 14:16:27 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	window_labels(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 15, HEX_WHITE,
		"'ESC': close window");
}

static void	window_center(t_mlx *mlx)
{
	my_pixel_put(mlx->img, WIN_WIDTH / 2, WIN_HEIGHT / 2, HEX_WHITE);
	my_pixel_put(mlx->img, WIN_WIDTH / 2 + 1, WIN_HEIGHT / 2, HEX_WHITE);
	my_pixel_put(mlx->img, WIN_WIDTH / 2 - 1, WIN_HEIGHT / 2, HEX_WHITE);
	my_pixel_put(mlx->img, WIN_WIDTH / 2, WIN_HEIGHT / 2 + 1, HEX_WHITE);
	my_pixel_put(mlx->img, WIN_WIDTH / 2, WIN_HEIGHT / 2 - 1, HEX_WHITE);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	window_labels(mlx);
}

int	window_init(t_mlx *mlx)
{
	if (!mlx)
		return (0);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (0);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"MiniRT");
	if (!mlx->win_ptr)
		return (0);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!(mlx->img.img_ptr))
		return (0);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	window_center(mlx);
	return (1);
}

void	my_pixel_put(t_img img, int x, int y, int color)
{
	char	*pixel;

	pixel = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	window_destroy(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free(mlx);
}
