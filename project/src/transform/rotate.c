/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:46:37 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/24 18:29:54 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	rotate_cylinder(t_cylinder *cylinder, int keycode)
{
	if (keycode == XK_u)
		cylinder->direction->x += ROTATION_RATIO;
	else if (keycode == XK_j)
		cylinder->direction->x -= ROTATION_RATIO;
	else if (keycode == XK_i)
		cylinder->direction->y += ROTATION_RATIO;
	else if (keycode == XK_k)
		cylinder->direction->y -= ROTATION_RATIO;
	else if (keycode == XK_o)
		cylinder->direction->z += ROTATION_RATIO;
	else
		cylinder->direction->z -= ROTATION_RATIO;
}

void	rotate_camera(t_mlx_scene *mlx_scene, int keycode)
{
	t_camera	*camera;

	camera = t_scene_get_camera(mlx_scene->scene);
	if (keycode == XK_t)
	{
		(*camera).v.y -= ROTATION_CAMERA_RATIO;
		(*camera).w.y -= ROTATION_CAMERA_RATIO;
	}
	else if (keycode == XK_g)
	{
		(*camera).v.y += ROTATION_CAMERA_RATIO;
		(*camera).w.y += ROTATION_CAMERA_RATIO;
	}
	else if (keycode == XK_f)
	{
		(*camera).u.x -= ROTATION_CAMERA_RATIO;
		(*camera).w.x -= ROTATION_CAMERA_RATIO;
	}
	else if (keycode == XK_h)
	{
		(*camera).u.x += ROTATION_CAMERA_RATIO;
		(*camera).w.x += ROTATION_CAMERA_RATIO;
	}
	render(&mlx_scene->mlx, mlx_scene->scene);
}

void	rotate(t_mlx_scene *mlx_scene, int keycode)
{
	t_scene		**scene;

	scene = &mlx_scene->scene;
	while (scene && *scene && (*scene)->next)
	{
		if ((*scene)->type == CYLINDER)
			break ;
		*scene = (*scene)->next;
	}
	if ((*scene)->type == CYLINDER)
		rotate_cylinder((t_cylinder *)(*scene)->data, keycode);
	t_scene_set_to_head(scene);
	render(&mlx_scene->mlx, (*scene));
	return ;
}
