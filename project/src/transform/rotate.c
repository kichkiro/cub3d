/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:46:37 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/17 19:42:17 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	rotate_camera(t_mlx_scene *mlx_scene, int keycode)
{
	t_camera	*camera;

	camera = t_scene_get_camera(mlx_scene->scene);
	if (keycode == XK_z && camera->direction->x < 1)
		camera->direction->x += ROTATION_RATIO;
	else if (keycode == XK_x && camera->direction->x > -1)
		camera->direction->y -= ROTATION_RATIO;
	else if (keycode == XK_c && camera->direction->y < 1)
		camera->direction->y += ROTATION_RATIO;
	else if (keycode == XK_v && camera->direction->y > -1)
		camera->direction->x -= ROTATION_RATIO;
	log_key_hook(keycode);
	log_camera(camera);
	render(&mlx_scene->mlx, mlx_scene->scene);
}
