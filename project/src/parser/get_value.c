/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:07:49 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/06 14:25:43 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

double	get_value(char **line)
{
	char	*tmp;
	double	value;

	tmp = ft_calloc(1, sizeof(char));
	while (line && *line && **line && **line != 44 && **line != 32 && \
		**line != 9)
	{
		tmp = ft_char_append(tmp, **line, true);
		(*line)++;
	}
	(*line)++;
	value = ft_atof(tmp);
	ft_free((void **)&tmp);
	return (value);
}

t_coords	*get_coords(char **line)
{
	t_coords	*coords;

	coords = (t_coords *)malloc(sizeof(t_coords));
	if (!coords)
		errors_handler("malloc()", NULL, NULL);
	while (line && *line && (**line == 9 || **line == 32))
		(*line)++;
	coords->x = get_value(line);
	coords->y = get_value(line);
	coords->z = get_value(line);
	// printf("x: %f\ny: %f\nz: %f\n", coords->x, coords->y, coords->z);
	return (coords);
}

t_rgb	*get_rgb(char **line)
{
	t_rgb	*rgb;

	rgb = (t_rgb *)malloc(sizeof(t_rgb));
	if (!rgb)
		errors_handler("malloc()", NULL, NULL);
	while (line && *line && (**line == 9 || **line == 32))
		(*line)++;
	rgb->red = get_value(line);
	rgb->green = get_value(line);
	rgb->blue = get_value(line);
	// printf("red: %d\ngreen: %d\nblue: %d\n", rgb->red, rgb->green, rgb->blue);
	return (rgb);
}
