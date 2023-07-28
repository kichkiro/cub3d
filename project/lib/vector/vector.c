/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:54:13 by anvannin          #+#    #+#             */
/*   Updated: 2023/07/28 19:29:11 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*!
	@brief	Distance between two points.
	@param	a	First point.
	@param	b	Second point.
	@return	The vector between two points.
*/
float	v_distance(t_coords a, t_coords b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2)));
}

/*!
	@brief	Add two vectors.
	@param	a	First vector.
	@param	b	Second vector.
	@return	The sum of two vectors.
*/
t_coords	v_add(t_coords a, t_coords b)
{
	t_coords	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

/*!
	@brief	Subtract two vectors.
	@param	a	First vector.
	@param	b	Second vector.
	@return	The difference of two vectors.
*/
t_coords	v_subtract(t_coords a, t_coords b)
{
	t_coords	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return (result);
}

/*!
	@brief	Find the dot product of two vectors.
	@param	a	First vector.
	@param	b	Second vector.
	@return	The dot product of two vectors.
	@note	The dot product or scalar product is an algebraic operation that
			takes two equal-length sequences of numbers (usually coordinate
			vectors), and returns a single number
*/
double	v_dot_product(t_coords a, t_coords b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

/*!
	@brief	Find the cross product of two vectors.
	@param	a	First vector.
	@param	b	Second vector.
	@return	The cross product of two vectors.
	@note	The cross product of two vectors a and b is a vector that is
			perpendicular to both a and b, and thus normal to the plane
			containing them.
*/
t_coords	v_cross(t_coords a, t_coords b)
{
	t_coords	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}
