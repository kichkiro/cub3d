/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:27:32 by anvannin          #+#    #+#             */
/*   Updated: 2023/07/29 12:23:07 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

typedef struct s_coords
{
	double	x;
	double	y;
	double	z;
}	t_coords;

// vector.c
float		v_distance(t_coords a, t_coords b);
t_coords	v_add(t_coords a, t_coords b);
t_coords	v_subtract(t_coords a, t_coords b);
double		v_dot_product(t_coords a, t_coords b);
t_coords	v_cross(t_coords a, t_coords b);

// vector2.c
double		v_module(t_coords a);

#endif
