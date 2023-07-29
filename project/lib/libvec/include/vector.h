/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:27:32 by anvannin          #+#    #+#             */
/*   Updated: 2023/07/29 21:39:58 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

# define PI 3.14159265358979323846

typedef struct s_coords
{
	double	x;
	double	y;
	double	z;
}	t_coords;

// vector_base.c
float		v_distance(t_coords a, t_coords b);
t_coords	v_add(t_coords a, t_coords b);
t_coords	v_subtract(t_coords a, t_coords b);
double		v_dot_product(t_coords a, t_coords b);
t_coords	v_cross(t_coords a, t_coords b);

// vector_adv.c
double		v_module(t_coords a);
t_coords	v_normalize(t_coords a);
double		v_cos(t_coords a, t_coords b);
double		v_sin(t_coords a, t_coords b);
t_coords	v_scale(t_coords a, double scale);

// vector_rot.c
t_coords	v_rotate_x(t_coords v, double angle);
t_coords	v_rotate_y(t_coords v, double angle);
t_coords	v_rotate_z(t_coords v, double angle);

#endif
