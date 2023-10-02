/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:18:44 by kichkiro          #+#    #+#             */
/*   Updated: 2023/09/28 10:38:37 by kichkiro         ###   ########.fr       */
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

/*!
 * @brief 
	Checks whether the first character starts with lowercase or uppercase 
	letter.
	If it is unique, check that there are no other objects of the same type
	in the list of objects in the scene.
	If it is not unique, it checks that there is no other object of the same 
	type labeled as unique. 
 * @param line
	The line of the .rt file to be parsed.
 * @param scene 
	Pointer to the linked list that contains the objects in the scene.
 * @param type 
	The type of the scene object.
 * @return 
	true if obj is unique, false otherwise.
 */
static bool	get_unique(char *line, t_scene *scene, char type)
{
	bool	unique;

	if (*line > 64 && *line < 91)
		unique = true;
	else if (*line > 96 && *line < 123)
		unique = false;
	else
		errors_handler("parser: the first character of the type must be a "\
			"letter", NULL, NULL);
	if (!t_scene_check_unique(scene, type, unique))
		errors_handler("parser: there can be a single object of the same type "\
			"if its type starts with a capital letter ", NULL, NULL);
	return (unique);
}

static void	*get_data(char *line, char type)
{
	while (*line != 32 && *line != 9)
		line++;
	if (type == AMBIENT_LIGHTNING)
		return (parse_ambient_lightning(line));
	else if (type == LIGHT)
		return (parse_light(line));
	else if (type == CAMERA)
		return (parse_camera(line));
	else if (type == SPHERE)
		return (parse_sphere(line));
	else if (type == PLANE)
		return (parse_plane(line));
	else if (type == CYLINDER)
		return (parse_cylinder(line));
	return (NULL);
}

void	parser(char *filename, t_scene **scene)
{
	char	*line;
	int		id;
	char	type;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		errors_handler("open()", NULL, NULL);
	id = 0;
	while (true)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		else if (*line == 10 && !ft_free((void **)&line))
			continue ;
		type = get_type(line);
		t_scene_add_back(scene, t_scene_new(id, type, get_unique(line, *scene, \
			type), get_data(line, type)));
		ft_free((void **)&line);
		id++;
	}
}
