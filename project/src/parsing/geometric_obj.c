/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:44:38 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/02 19:59:26 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	*parse_sphere(char *line, t_scene *scene)
{
	t_sphere	*spere;

	spere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!spere)
		errors_handler("parser: malloc()", NULL, &scene);
	spere->origin = get_coords(&line, scene);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	spere->diameter = get_value(&line, scene);
	spere->rgb = get_rgb(&line, scene);
	return ((void *)spere);
}

void	*parse_plane(char *line, t_scene *scene)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		errors_handler("parser: malloc()", NULL, &scene);
	plane->origin = get_coords(&line, scene);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	plane->direction = get_coords(&line, scene);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	plane->rgb = get_rgb(&line, scene);
	return ((void *)plane);
}

void	*parse_cylinder(char *line, t_scene *scene)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)
		errors_handler("parser: malloc()", NULL, &scene);
	cylinder->origin = get_coords(&line, scene);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	cylinder->direction = get_coords(&line, scene);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	cylinder->diameter = get_value(&line, scene);
	cylinder->height = get_value(&line, scene);
	cylinder->rgb = get_rgb(&line, scene);
	return ((void *)cylinder);
}
