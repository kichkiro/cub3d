/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_scene_get_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:20:36 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/01 21:23:09 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_camera	*t_scene_get_camera(t_scene *scene)
{
    t_scene_set_to_head(&scene);
	while (scene && scene->type != CAMERA)
		scene = scene->next;
	return ((t_camera *)scene->data);
}

t_light	*t_scene_get_light(t_scene *scene)
{
    t_scene_set_to_head(&scene);
	while (scene && scene->type != LIGHT)
		scene = scene->next;
	return ((t_light *)scene->data);
}

t_ambient_lightning	*t_scene_get_ambient_light(t_scene *scene)
{
    t_scene_set_to_head(&scene);
	while (scene && scene->type != AMBIENT_LIGHTNING)
		scene = scene->next;
	return ((t_ambient_lightning *)scene->data);
}
