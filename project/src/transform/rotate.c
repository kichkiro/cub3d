/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:46:37 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/19 19:29:38 by anvannin         ###   ########.fr       */
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
	log_key_hook(keycode);
	log_cylinder(cylinder);
}

void	rotate_camera(t_mlx_scene *mlx_scene, int keycode)
{
	t_camera	*camera;

	camera = t_scene_get_camera(mlx_scene->scene);
	if (keycode == XK_t && camera->direction->x < 1)
		(*camera).u = v_rotate_y((*camera).u, ROTATION_RATIO);
	else if (keycode == XK_g && camera->direction->x > -1)
		(*camera).v.z += ROTATION_RATIO;
	else if (keycode == XK_f && camera->direction->y < 1)
		(*camera).w.z -= ROTATION_RATIO;
	// else if (keycode == XK_f && camera->direction->x > -1)
	// 	(*camera).u.x -= ROTATION_RATIO;
	// else if (keycode == XK_g && camera->direction->y < 1)
	// 	(*camera).u.z += ROTATION_RATIO;
	// else if (keycode == XK_h && camera->direction->y > -1)
	// 	(*camera).u.z -= ROTATION_RATIO;
	log_key_hook(keycode);
	log_camera(camera);
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
