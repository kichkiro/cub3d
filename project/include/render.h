/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:35:53 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/24 21:57:43 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

// Libraries ------------------------------------------------------------------>

# include "minirt.h"

// Defines -------------------------------------------------------------------->

# define EPSILON 0.00001

// Structures ----------------------------------------------------------------->

/*!
 * @brief
	It represents the record of an intersection between a ray and an object in a
	3D scene.
 * @param has_intersec
	Flag indicating whether an intersec occurred.
 * @param point
	The point of intersec in 3D space.
 * @param normal
	The surface normal at the intersec point.
 * @param color
	The color of the surface at the intersec point.
 * @param nearest
  	The nearest intersec distance along the ray.
 * @param min
	Minimum intersec distance to consider.
 * @param max
	Maximum intersec distance to consider.
 */
typedef struct s_intersec
{
	bool		has_intersec;
	t_v3		point;
	t_v3		normal;
	t_rgb		color;
	double		nearest;
	double		min;
	double		max;
}	t_intersec;

typedef struct s_ray
{
	t_v3		origin;
	t_v3		direction;
}	t_ray;

typedef struct s_texture_coords
{
	double		u;
	double		v;
}	t_texture_coords;

typedef struct s_raycaster
{
	double	sfactor;
	double	dfactor;
	double	len;
	t_ray	shadow_ray;
	t_v3	ambient;
	t_v3	diffuse;
	t_v3	light;
	t_v3	specular;
	t_v3	viewdir;
	t_v3	reflect;
	t_v3	color;
}	t_lighting;

typedef struct s_hit
{
	t_v3	x;
	t_v3	p;
	t_v3	diff;
	t_v3	pcent;
	double	dv;
	double	xv;
	double	a;
	double	hb;
	double	c;
	double	dis;
	double	t;
	double	t2;
	double	sdis;
	double	dtop;
}	t_hit;

// Functions ------------------------------------------------------------------>

void	render(t_mlx **mlx, t_scene *scene);
int		raycaster(t_scene *scene, t_camera *cam, int x, int y);
void	intersections(t_scene *scene, t_ray ray, t_intersec *isec);
bool	intersec_cylinder(t_ray *ray, t_cylinder *cy, t_intersec **isec);
bool	intersec_sphere(t_ray *ray, t_sphere *sp, t_intersec **isec);
bool	intersec_plane(t_ray *ray, t_plane *pl, t_intersec **isec);

int		rgb_to_int(t_rgb *rgb);
int		rgb_to_int2(int r, int g, int b);
void	print_rgb_int(t_rgb *rgb);
void	print_rgb_hex(t_rgb *rgb);
t_rgb	v3_to_rgb(t_v3 v);
t_v3	rgb_to_v3(t_rgb rgb);

#endif
