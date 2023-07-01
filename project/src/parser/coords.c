/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 10:59:55 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/01 13:19:30 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
	// printf("x: %f\ny: %f\nz: %f\n", coords->x, coords->y, coords->z);
	return (coords);
}
