/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:40:47 by anvannin          #+#    #+#             */
/*   Updated: 2023/07/05 20:09:48 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	mlx_exit(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free(mlx);
	exit(0);
}

static int	mouse_handler(int key, int x, int y, t_mlx *mlx)
{
	if (key == 1)
		printf("right button pressed: %d %d\n", x, y);
	else if (key == 2)
		printf("left button pressed: %d %d\n", x, y);
	else
		return (0);
	return (1);
	mlx_exit(mlx);
}

static int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		return (mlx_exit(mlx));
	else
		return (0);
	return (1);
}

int	hooks_init(t_mlx *mlx)
{
	mlx_do_key_autorepeaton(mlx->mlx_ptr);
	mlx_hook(mlx->win_ptr, 17, 1L << 17, mlx_exit, mlx);
	mlx_hook(mlx->win_ptr, 2, 1l << 0, &key_hook, mlx);
	mlx_mouse_hook(mlx->win_ptr, &mouse_handler, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (1);
}
