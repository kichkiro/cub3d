/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:18:44 by kichkiro          #+#    #+#             */
/*   Updated: 2023/09/07 11:31:43 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	get_type(char *line)
{
	if (!ft_strncmp(line, "SP", 2) || !ft_strncmp(line, "sp", 2))
		return (SPHERE);
	else if (!ft_strncmp(line, "PL", 2) || !ft_strncmp(line, "pl", 2))
		return (PLANE);
	else if (!ft_strncmp(line, "CY", 2) || !ft_strncmp(line, "cy", 2))
		return (CYLINDER);
	else if (!ft_strncmp(line, "A", 1) || !ft_strncmp(line, "a", 1))
		return (AMBIENT_LIGHTNING);
	else if (!ft_strncmp(line, "C", 1) || !ft_strncmp(line, "c", 1))
		return (CAMERA);
	else if (!ft_strncmp(line, "L", 1) || !ft_strncmp(line, "l", 1))
		return (LIGHT);
	else
		errors_handler("Invalid identifier", NULL, NULL);
	return (0);
}

static bool	get_unique(char *line)
{
	if (line[0] < 97)
		return (false);
	return (true);
}

static void	*get_data(char *line, char type)
{
	while (*line != 32 && *line != 9)
		line++;
	if (type == AMBIENT_LIGHTNING)
		return (parse_ambient_lightning(line));
	else if (type == CAMERA)
		return (parse_camera(line));
	else if (type == LIGHT)
		return (parse_light(line));
	else if (type == SPHERE)
		return (parse_sphere(line));
	else if (type == PLANE)
		return (parse_plane(line));
	else if (type == CYLINDER)
		return (parse_cylinder(line));
	return (NULL);
}

t_scene	*get_scene(char	*filename)
{
	t_scene	*scene;
	char	*line;
	int		id;
	char	type;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		errors_handler("open()", NULL, &scene);
	scene = NULL;
	id = 0;
	while (true)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		else if (*line == 10)
		{
			ft_free((void **)&line);
			continue ;
		}
		type = get_type(line);
		t_scene_add_back(&scene, t_scene_new(id, type, get_unique(line), \
			get_data(line, type)));
		ft_free((void **)&line);
		id++;
	}
	return (scene);
}
