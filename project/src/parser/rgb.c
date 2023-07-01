/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:10:43 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/01 13:19:30 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
	// printf("red: %d\ngreen: %d\nblue: %d\n", rgb->red, rgb->green, rgb->blue);
	return (rgb);
}
