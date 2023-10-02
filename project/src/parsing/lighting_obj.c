/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 12:46:26 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/02 17:01:29 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	*parse_ambient_lightning(char *line)
{
	t_ambient_lightning	*am_light;

	am_light = (t_ambient_lightning *)malloc(sizeof(t_ambient_lightning));
	if (!am_light)
		errors_handler("malloc()", NULL, NULL);
	am_light->ratio = get_value(&line);
	while (line && *line && (ft_isdigit(*line) || *line == 46))
		line++;
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	am_light->rgb = get_rgb(&line);
	am_light->rgb->red /= 255;
	am_light->rgb->green /= 255;
	am_light->rgb->blue /= 255;
	return ((void *)am_light);
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
	light->rgb->red /= 255;
	light->rgb->green /= 255;
	light->rgb->blue /= 255;
	return ((void *)light);
}
