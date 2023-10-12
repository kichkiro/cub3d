/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traslate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:52:26 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/12 21:48:25 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	traslate(t_mlx_scene *mlx_scene, int keycode)
{
	t_sphere	*sphere;
	t_scene		**scene;

	scene = &mlx_scene->scene;
	sphere = malloc(sizeof(t_sphere));
	// while (scene && *scene && (*scene)->next)
	// {
	// 	if ((*scene)->type == SPHERE)
	// 	{
	// 		sphere = (t_sphere *)(*scene)->data;
	// 		break ;
	// 	}
	// 	*scene = (*scene)->next;
	// }

	// if (keycode == XK_Shift_L)
	// 	sphere->coords->y += 10;
	// else if (keycode == XK_Control_L)
	// 	sphere->coords->y -= 10;
	// else if (keycode == XK_Up)
	// 	sphere->coords->z += 10;
	// else if (keycode == XK_Right)
	// 	sphere->coords->x += 10;
	// else if (keycode == XK_Down)
	// 	sphere->coords->z -= 10;
	// else
	// 	sphere->coords->x -= 10;

	// log_key_hook(keycode);
	// log_sphere(sphere);
	// mlx_destroy_image(mlx_scene->mlx->mlx_ptr, mlx_scene->mlx->img.img_ptr);

	// visualizator(mlx_scene->mlx, scene);
	// render(mlx_scene->mlx, scene);
	return ;
	(void)scene;
	(void)sphere;
	(void)mlx_scene;
}
