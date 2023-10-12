/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_labels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:38:32 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/12 21:39:52 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	objects_labels(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 60, HEX_WHITE,
		"+++OBJECTS+++");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 75, HEX_WHITE,
		"Right click: select an object to move");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 90, HEX_WHITE,
		"'Left/Right' arrows: move object left/right");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 105, HEX_WHITE,
		"'Up/Down' arrows: move object farther/closer");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 120, HEX_WHITE,
		"'Shift/Ctrl': move object up/down");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 135, HEX_WHITE,
		"'Left click': deselect object");
}

static void	camera_labels(t_mlx *mlx)
{
	int	width;

	width = WIN_WIDTH - 220;
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, width, 15, HEX_WHITE,
		"+++CAMERA+++");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, width, 30, HEX_WHITE,
		"'W/S': move camera forward/backward");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, width, 45, HEX_WHITE,
		"'A/D': move camera left/right");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, width, 60, HEX_WHITE,
		"'Q/E': move camera up/down");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, width, 75, HEX_WHITE,
		"Scroll up/down: zoom in/out");
}

// left/right arrows: move object left/right
// up/down arrows: move object farther/closer
// shift/ctrl: move object up/down
void	window_labels(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 15, HEX_WHITE,
		"+++SYSTEM+++");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 30, HEX_WHITE,
		"'Esc: close window");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 45, HEX_WHITE,
		"'R': reset scene");
	objects_labels(mlx);
	camera_labels(mlx);
}
