/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 12:46:19 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/02 19:59:33 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	*parse_camera(char *line, t_scene *scene)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		errors_handler("parser: malloc()", NULL, &scene);
	camera->origin = get_coords(&line, scene);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	camera->direction = get_coords(&line, scene);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	camera->fov = get_value(&line, scene);
	camera->w = v_unit(v_sub_vec((*camera->origin), (t_v3){0, 0, 0}));
	camera->u = v_unit(v_cross(v_unit((*camera->direction)), camera->w));
	camera->v = v_cross(camera->w, camera->u);
	camera->d = 1.0 / tanf(camera->fov * 0.5 * 3.1415 / 180.0);
	return ((void *)camera);
}
