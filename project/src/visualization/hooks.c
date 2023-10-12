/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:40:47 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/12 21:04:39 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// left/right arrows: move object left/right
// up/down arrows: move object farther/closer
// shift/ctrl: move object up/down
static int	objects_hooks(int keycode, t_mlx_scene *mlx_scene)
{
	if (keycode == XK_Shift_L || keycode == XK_Control_L || keycode == XK_Up
		|| keycode == XK_Right || keycode == XK_Down || keycode == XK_Left)
		traslate(mlx_scene, keycode);
	else
		return (0);
	return (1);
}

// w/s: move camera forward/backward
// a/d: move camera left/right
// q/e: move camera up/down
static int	camera_hooks(int keycode)
{
	if (keycode == XK_w || keycode == XK_s || keycode == XK_a || keycode == XK_d
		|| keycode == XK_q || keycode == XK_e)
		log_key_hook(keycode);
	else
		return (0);
	return (1);
}

// esc: close window
// r: reset scene
int	key_hook(int keycode, t_mlx_scene *mlx_scene)
{
	if (keycode == XK_Escape)
		return (mlx_exit(mlx_scene->mlx));
	else if (keycode == XK_r)
		printf("R pressed\n");
	else if (objects_hooks(keycode, mlx_scene))
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
	if (key == 1 || key == 2 || key == 4 || key == 5)
		log_mouse_hook(key, x, y);
	else
		return (0);
	return (1);
	mlx_exit(mlx);
}
