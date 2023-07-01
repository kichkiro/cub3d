/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 10:59:55 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/01 11:10:50 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static double	get_value(char **line)
{
	char	*tmp;
	double	value;

	tmp = ft_calloc(1, sizeof(char));
	while (line && *line && **line != 44 && **line != 32 && **line != 9)
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
		ft_fatal("malloc()");
	while (line && *line && (**line == 9 || **line == 32))
		(*line)++;
	coords->x = get_value(line);
	coords->y = get_value(line);
	coords->z = get_value(line);
	printf("x: %f\ny: %f\nz: %f\n", coords->x, coords->y, coords->z);
	return (coords);
}
