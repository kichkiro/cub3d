/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traslate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:52:26 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/16 20:06:53 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	traslate_sphere(t_sphere *sphere, int keycode)
{
	if (keycode == XK_Shift_L)
		sphere->origin->y += TRASTLATION_RATIO;
	else if (keycode == XK_Control_L)
		sphere->origin->y -= TRASTLATION_RATIO;
	else if (keycode == XK_Up)
		sphere->origin->z += TRASTLATION_RATIO;
	else if (keycode == XK_Right)
		sphere->origin->x -= TRASTLATION_RATIO;
	else if (keycode == XK_Down)
		sphere->origin->z -= TRASTLATION_RATIO;
	else
		sphere->origin->x += TRASTLATION_RATIO;

	log_key_hook(keycode);
	log_sphere(sphere);
}

void	traslate(t_mlx_scene *mlx_scene, int keycode)
{
	t_scene		**scene;
	t_mlx		*mlx;

	mlx = mlx_scene->mlx;
	// t_scene_get_selected(scene);
	scene = &mlx_scene->scene;
	while (scene && *scene && (*scene)->next)
	{
		if ((*scene)->type == SPHERE)
			break ;
		*scene = (*scene)->next;
	}
	if ((*scene)->type == SPHERE)
		traslate_sphere((t_sphere *)(*scene)->data, keycode);
	t_scene_set_to_head(scene);
	render(&mlx, (*scene));
	return ;
}
