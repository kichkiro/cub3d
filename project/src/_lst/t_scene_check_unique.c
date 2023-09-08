/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_scene_check_unique.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:50:31 by kichkiro          #+#    #+#             */
/*   Updated: 2023/09/08 14:55:20 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*!
 * @brief 
	Check that there is only one object with unique type.
 * @param scene 
	Pointer to the linked list that contains the objects in the scene.
 * @param type 
	Type to check.
 * @return 
	true if there is only one object with unique type, false otherwise.
 */
bool	t_scene_check_unique(t_scene *scene, char type, bool unique)
{
	t_scene_set_to_head(&scene);
	while (scene)
	{
		if ((unique && scene->type == type) || (!unique && scene->type == type \
			&& scene->unique))
			return (false);
		scene = scene->next;
	}
	return (true);
}
