/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:40:47 by anvannin          #+#    #+#             */
/*   Updated: 2023/09/28 10:47:13 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


// left/right arrows: move object left/right
// up/down arrows: move object farther/closer
// shift/ctrl: move object up/down
static int	objects_hooks(int keycode)
{
	if (keycode == XK_Shift_L)
		printf("shift pressed\n");
	else if (keycode == XK_Control_L)
		printf("control pressed\n");
	else if (keycode == XK_Up)
		printf("up arrow pressed\n");
	else if (keycode == XK_Right)
		printf("right arrow pressed\n");
	else if (keycode == XK_Down)
		printf("down arrow pressed\n");
	else if (keycode == XK_Left)
		printf("left arrow pressed\n");
	else
		return (0);
	return (1);
}

// w/s: move camera forward/backward
// a/d: move camera left/right
// q/e: move camera up/down
static int	camera_hooks(int keycode)
{
	if (keycode == XK_w)
		printf("w pressed\n");
	else if (keycode == XK_s)
		printf("s pressed\n");
	else if (keycode == XK_a)
		printf("a pressed\n");
	else if (keycode == XK_d)
		printf("d pressed\n");
	else if (keycode == XK_q)
		printf("q pressed\n");
	else if (keycode == XK_e)
		printf("e pressed\n");
	else
		return (0);
	return (1);
}

// esc: close window
// r: reset scene
int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		return (mlx_exit(mlx));
	else if (keycode == XK_r)
		printf("R pressed\n");
	else if (objects_hooks(keycode))
		return (1);
	else if (camera_hooks(keycode))
		return (1);
	else
		return (0);
	return (1);
}

// left click: select object to move
// right click: deselect object
// scroll up/down: zoom in/out
int	mouse_hooks(int key, int x, int y, t_mlx *mlx)
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
