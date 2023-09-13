/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:45:57 by kichkiro          #+#    #+#             */
/*   Updated: 2023/09/13 08:48:49 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

// Libraries ------------------------------------------------------------------>

# include "minirt.h"
# include <fcntl.h>

typedef struct s_scene	t_scene;

// Defines -------------------------------------------------------------------->

# define AMBIENT_LIGHTNING	1
# define CAMERA				2
# define LIGHT				3
# define SPHERE				4
# define PLANE				5
# define CYLINDER			6

// Structures ----------------------------------------------------------------->

typedef struct s_rgb
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}	t_rgb;

typedef struct s_ambient_lightning
{
	double	ratio;
	t_rgb	*rgb;
}	t_ambient_lightning;

typedef struct s_camera
{
	t_coords		*coords;
	t_coords		*norm_vect;
	unsigned char	fov;
}	t_camera;

typedef struct s_light
{
	t_coords	*coords;
	double		brightness;
	t_rgb		*rgb;
}	t_light;

typedef struct s_sphere
{
	t_coords	*coords;
	double		diameter;
	t_rgb		*rgb;
}	t_sphere;

typedef struct s_plane
{
	t_coords	*coords;
	t_coords	*norm_vect;
	t_rgb		*rgb;
}	t_plane;

typedef struct s_cylinder
{
	t_coords	*coords;
	t_coords	*norm_vect;
	double		diameter;
	double		height;
	t_rgb		*rgb;
}	t_cylinder;

// Linked Lists --------------------------------------------------------------->

typedef struct s_scene
{
	int				id;
	char			type;
	bool			unique;
	void			*data;
	struct s_scene	*prev;
	struct s_scene	*next;
}	t_scene;

t_scene		*t_scene_new(int id, char type, bool unique, void *data);
void		t_scene_add_back(t_scene **lst, t_scene *new);
void		t_scene_set_to_head(t_scene **scene);
void		t_scene_free(t_scene **scene);
t_scene		*t_scene_find_obj_by_id(t_scene *scene, int id);
bool		t_scene_check_unique(t_scene *scene, char type, bool unique);

// Functions ------------------------------------------------------------------>

t_scene		*get_scene(char	*filename);
t_coords	*get_coords(char **line);
t_rgb		*get_rgb(char **line);
double		get_value(char **line);
void		*parse_ambient_lightning(char *line);
void		*parse_camera(char *line);
void		*parse_light(char *line);
void		*parse_sphere(char *line);
void		*parse_plane(char *line);
void		*parse_cylinder(char *line);

#endif
