/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 12:46:19 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/01 13:19:58 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	*parse_camera(char *line)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		ft_fatal("malloc()");
	camera->coords = get_coords(&line);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	camera->norm_vect = get_coords(&line);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	camera->fov = get_value(&line);
	return ((void *)camera);
}
