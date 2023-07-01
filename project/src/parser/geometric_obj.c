/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:44:38 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/01 13:19:30 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	*parse_sphere(char *line)
{
	t_sphere	*spere;

	spere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!spere)
		ft_fatal("malloc()");
	spere->coords = get_coords(&line);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	spere->diameter = get_value(&line);
	spere->rgb = get_rgb(&line);
	return ((void *)spere);
}

void	*parse_plane(char *line)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		ft_fatal("malloc()");
	plane->coords = get_coords(&line);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	plane->norm_vect = get_coords(&line);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	plane->rgb = get_rgb(&line);
	return ((void *)plane);
}

void	*parse_cylinder(char *line)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)
		ft_fatal("malloc()");
	cylinder->coords = get_coords(&line);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	cylinder->norm_vect = get_coords(&line);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	cylinder->diameter = get_value(&line);
	cylinder->height = get_value(&line);
	cylinder->rgb = get_rgb(&line);
	return ((void *)cylinder);
}
