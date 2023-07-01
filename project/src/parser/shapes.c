/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:44:38 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/01 11:25:42 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	*parse_sphere(char *line)
{
	t_sphere	*spere;
	char		*tmp;

	spere->coords = get_coords(&line);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	tmp = NULL;
	while (line && *line && *line != 44 && *line != 32 && *line != 9)
	{
		tmp = ft_char_append(tmp, *line, true);
		line++;
	}
	spere->diameter = ft_atof(tmp);
	ft_free((void **)&tmp);
	spere->rgb = get_rgb(&line);
	return ((void *)spere);
}
