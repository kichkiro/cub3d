/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_scene_find_obj_by_id.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:46:40 by kichkiro          #+#    #+#             */
/*   Updated: 2023/09/07 12:13:41 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_scene	*t_scene_find_obj_by_id(t_scene *scene, int id)
{
	t_scene_set_to_head(&scene);
	while (scene && scene->id != id)
		scene = scene->next;
	return (scene);
}
