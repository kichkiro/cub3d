/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:10:43 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/01 11:13:53 by kichkiro         ###   ########.fr       */
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
	value = ft_atoi(tmp);
	ft_free((void **)&tmp);
	return (value);
}

t_rgb	*get_rgb(char **line)
{
	t_rgb	*rgb;

	rgb = (t_rgb *)malloc(sizeof(t_rgb));
	if (!rgb)
		ft_fatal("malloc()");
	while (line && *line && (**line == 9 || **line == 32))
		(*line)++;
	rgb->red = get_value(line);
	rgb->green = get_value(line);
	rgb->blue = get_value(line);
	printf("red: %d\ngreen: %d\nblue: %d\n", rgb->red, rgb->green, rgb->blue);
	return (rgb);
}
