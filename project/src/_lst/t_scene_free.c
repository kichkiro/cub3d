/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_scene_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:58:44 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/06 11:55:21 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	t_scene_free(t_scene **scene)
{
	t_scene	*tmp;

	tmp = NULL;
	while ((*scene)->prev)
		(*scene) = (*scene)->prev;

	while ((*scene))
	{
		if ((*scene)->id == AMBIENT_LIGHTNING)
		{
			free(((t_ambient_lightning *)(*scene)->data)->rgb);
			free(((t_ambient_lightning *)(*scene)->data));
		}
		else if ((*scene)->id == CAMERA)
		{
			free(((t_camera *)(*scene)->data)->coords);
			free(((t_camera *)(*scene)->data)->norm_vect);
			free(((t_camera *)(*scene)->data));
		}
		else if ((*scene)->id == LIGHT)
		{
			free(((t_light *)(*scene)->data)->coords);
			free(((t_light *)(*scene)->data)->rgb);
			free(((t_light *)(*scene)->data));
		}
		else if ((*scene)->id == SPHERE)
		{
			free(((t_sphere *)(*scene)->data)->coords);
			free(((t_sphere *)(*scene)->data)->rgb);
			free(((t_sphere *)(*scene)->data));
		}
		else if ((*scene)->id == PLANE)
		{
			free(((t_plane *)(*scene)->data)->coords);
			free(((t_plane *)(*scene)->data)->norm_vect);
			free(((t_plane *)(*scene)->data)->rgb);
			free(((t_plane *)(*scene)->data));
		}
		else if ((*scene)->id == CYLINDER)
		{
			free(((t_cylinder *)(*scene)->data)->coords);
			free(((t_cylinder *)(*scene)->data)->norm_vect);
			free(((t_cylinder *)(*scene)->data)->rgb);
			free(((t_cylinder *)(*scene)->data));
		}

		tmp = *scene;
		*scene = (*scene)->next;
		free(tmp);
		if (*scene)
			(*scene)->prev = NULL;
	}
}
