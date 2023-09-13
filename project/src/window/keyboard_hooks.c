/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:23:35 by anvannin          #+#    #+#             */
/*   Updated: 2023/09/13 08:49:23 by kichkiro         ###   ########.fr       */
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
