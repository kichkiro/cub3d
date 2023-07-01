/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:07:49 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/01 13:19:38 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

double	get_value(char **line)
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
