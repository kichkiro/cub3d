/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_scene_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:38:34 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/06 14:44:24 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_scene	*t_scene_new(char id, bool unique, void *data)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		errors_handler("malloc()", NULL, &scene);
	scene->id = id;
	scene->unique = unique;
	scene->data = data;
	scene->prev = NULL;
	scene->next = NULL;
	return (scene);
}
