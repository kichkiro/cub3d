/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:13:53 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/02 20:04:50 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"

void	log_sphere(t_sphere *sp)
{
	int	left;
	int	right;
	int	top;
	int	bottom;

	left = (int)(sp->origin->x - sp->diameter / 2) + WIN_HEIGHT / 2;
	right = (int)(sp->origin->x + sp->diameter / 2) + WIN_HEIGHT / 2;
	top = (int)(sp->origin->y - sp->diameter / 2) + WIN_WIDTH / 2;
	bottom = (int)(sp->origin->y + sp->diameter / 2) + WIN_WIDTH / 2;
	printf("---------------------------SPHERE---------------------------\n");
	printf("x: %f\ty: %f\tz: %f\n", sp->origin->x, sp->origin->y,
		sp->origin->z);
	printf("radius: %f\tdiameter:%f\n", sp->diameter / 2, sp->diameter);
	printf("color: ");
	print_rgb_hex(sp->rgb);
	printf("center: [%d, %d]\n", (int)sp->origin->x + WIN_HEIGHT / 2,
		(int)sp->origin->y + WIN_WIDTH / 2);
	printf("\nleft: [%d, %d], right: [%d, %d]\n", left, WIN_HEIGHT / 2, right,
		WIN_HEIGHT / 2);
	printf("top: [%d, %d], bottom: [%d, %d]\n", top, WIN_WIDTH / 2, bottom,
		WIN_WIDTH / 2);
	printf("------------------------------------------------------------\n");
}

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
