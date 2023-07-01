/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:45:57 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/01 11:14:25 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

// Libraries ------------------------------------------------------------------>

# include "minirt.h"
# include <fcntl.h>

// Defines -------------------------------------------------------------------->

# define AMBIENT_LIGHTNING	1
# define CAMERA				2
# define LIGHT				3
# define SPHERE				4
# define PLANE				5
# define CYLINDER			6

// Structures ----------------------------------------------------------------->

typedef struct s_coords
{
	double			x;
	double			y;
	double			z;
}	t_coords;

typedef struct s_rgb
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}	t_rgb;

typedef struct s_ambient_lightning
{
	double			ratio;
	t_rgb			*rgb;
}	t_ambient_lightning;

typedef struct s_camera
{
	t_coords		*coords;
	t_coords		*norm_vect;
	unsigned char	fov;
}	t_camera;

typedef struct s_light
{
	t_coords		*coords;
	double			brightness;
	t_rgb			*rgb;
}	t_light;

typedef struct s_sphere
{
	t_coords		*coords;
	double			diameter;
	t_rgb			*rgb;
}	t_sphere;

typedef struct s_plane
{
	t_coords		*coords;
	t_coords		*norm_vect;
	t_rgb			*rgb;
}	t_plane;

typedef struct s_cylinder
{
	t_coords		*coords;
	t_coords		*norm_vect;
	double			diameter;
	double			height;
	t_rgb			*rgb;
}	t_cylinder;

// Linked Lists --------------------------------------------------------------->

typedef struct s_scene
{
	char			id;
	bool			unique;
	void			*data;
	struct s_scene	*prev;
	struct s_scene	*next;
}	t_scene;

t_scene		*t_scene_new(char id, bool unique, void *data);

// Functions ------------------------------------------------------------------>

t_scene		*get_scene(char	*filename);
t_coords	*get_coords(char **line);
t_rgb		*get_rgb(char **line);
void		*parse_sphere(char *line);

#endif
