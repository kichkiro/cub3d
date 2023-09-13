/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:40:47 by anvannin          #+#    #+#             */
/*   Updated: 2023/09/13 08:49:10 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// left click: select object to move
// right click: deselect object
// scroll up/down: zoom in/out
static int	mouse_handler(int key, int x, int y, t_mlx *mlx)
{
	if (key == 1)
		printf("left button pressed: %d %d\n", x, y);
	else if (key == 3)
		printf("right button pressed: %d %d\n", x, y);
	else if (key == 4)
		printf("scroll up\n");
	else if (key == 5)
		printf("scroll down\n");
	else
		return (0);
	return (1);
	mlx_exit(mlx);
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
