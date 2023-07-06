/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 12:46:26 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/06 14:25:49 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	*parse_ambient_lightning(char *line)
{
	t_ambient_lightning	*ambient_l;

	ambient_l = (t_ambient_lightning *)malloc(sizeof(t_ambient_lightning));
	if (!ambient_l)
		errors_handler("malloc()", NULL, NULL);
	ambient_l->ratio = get_value(&line);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	ambient_l->rgb = get_rgb(&line);
	return ((void *)ambient_l);
}

void	*parse_light(char *line)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		errors_handler("malloc()", NULL, NULL);
	light->coords = get_coords(&line);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	light->brightness = get_value(&line);
	light->rgb = get_rgb(&line);
	return ((void *)light);
}
