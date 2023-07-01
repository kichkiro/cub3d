/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:18:44 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/01 11:47:10 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	get_identifier(char *line)
{
	if (!ft_strncmp(line, "A", 1) || !ft_strncmp(line, "a", 1))
		return (AMBIENT_LIGHTNING);
	else if (!ft_strncmp(line, "C", 1) || !ft_strncmp(line, "c", 1))
		return (CAMERA);
	else if (!ft_strncmp(line, "L", 1) || !ft_strncmp(line, "l", 1))
		return (LIGHT);
	else if (!ft_strncmp(line, "SP", 2) || !ft_strncmp(line, "sp", 2))
		return (SPHERE);
	else if (!ft_strncmp(line, "PL", 2) || !ft_strncmp(line, "pl", 2))
		return (PLANE);
	else if (!ft_strncmp(line, "CY", 2) || !ft_strncmp(line, "cy", 2))
		return (CYLINDER);
	else
		ft_fatal("Invalid identifier");
	return (0);
}

static bool	get_unique(char *line)
{
	if (line[0] < 97)
		return (false);
	return (true);
}

static void	*get_data(char *line, char id)
{
	while (*line != 32 && *line != 9)
		line++;
	// if (id == AMBIENT_LIGHTNING)
		// return ();
	if (id == SPHERE)
		return (parse_sphere(line));
	return (NULL);
}

t_scene	*get_scene(char	*filename)
{
	t_scene	*scene;
	int		fd;
	char	*line;
	char	id;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_fatal("open()");
	scene = NULL;
	while (true)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		id = get_identifier(line);
		get_data(line, id);
		t_scene_add_back(&scene, t_scene_new(id, get_unique(line), get_data(line, id)));
		ft_free((void **)&line);
	}
	return (scene);
}
