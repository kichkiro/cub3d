/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_scene_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:58:44 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/06 14:12:08 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	free_lighting_obj(t_scene **scene)
{
	if ((*scene)->id == AMBIENT_LIGHTNING)
	{
		free(((t_ambient_lightning *)(*scene)->data)->rgb);
		free(((t_ambient_lightning *)(*scene)->data));
	}
	else if ((*scene)->id == LIGHT)
	{
		free(((t_light *)(*scene)->data)->coords);
		free(((t_light *)(*scene)->data)->rgb);
		free(((t_light *)(*scene)->data));
	}
}

static void	free_display_obj(t_scene **scene)
{
	if ((*scene)->id == CAMERA)
	{
		free(((t_camera *)(*scene)->data)->coords);
		free(((t_camera *)(*scene)->data)->norm_vect);
		free(((t_camera *)(*scene)->data));
	}
}

static void	free_geometric_obj(t_scene **scene)
{
	if ((*scene)->id == SPHERE)
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
}

void	t_scene_free(t_scene **scene)
{
	t_scene	*tmp;

	tmp = NULL;
	t_scene_set_to_head(scene);
	while ((*scene))
	{
		if ((*scene)->id == AMBIENT_LIGHTNING || (*scene)->id == LIGHT)
			free_lighting_obj(scene);
		else if ((*scene)->id == CAMERA)
			free_display_obj(scene);
		else if ((*scene)->id == SPHERE || (*scene)->id == PLANE || \
			(*scene)->id == CYLINDER)
			free_geometric_obj(scene);
		tmp = *scene;
		*scene = (*scene)->next;
		free(tmp);
		if (*scene)
			(*scene)->prev = NULL;
	}
}
