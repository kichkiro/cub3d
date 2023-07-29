/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_adv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:56:00 by anvannin          #+#    #+#             */
/*   Updated: 2023/07/29 15:47:42 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*!
	@brief	Module of a vector.
	@param	a	The vector.
	@return	The module of the vector.
	@note	The module of a vector is found by the square root of the dot
			product of the vector by itself.
*/
double	v_module(t_coords a)
{
	return (sqrt(v_dot_product(a, a)));
}

/*!
	@brief	Normalize a vector.
	@param	a	The vector.
	@return	The normalized vector.
	@note	The normalized vector is found by dividing each component of the
			vector by its module.
*/
t_coords	v_normalize(t_coords a)
{
	double		module;
	t_coords	norm;

	module = v_module(a);
	norm.x = a.x / module;
	norm.y = a.y / module;
	norm.z = a.z / module;
	return (norm);
}

/*!
	@brief	Cosinus of two vectors.
	@param	a	First vector.
	@param	b	Second vector.
	@return	The cosinus of two vectors.
	@note	The cosinus of two vectors is found by dividing the dot product of
			the two vectors by the product of their modules.
*/
double	v_cos(t_coords a, t_coords b)
{
	return (v_dot_product(a, b) / (v_module(a) * v_module(b)));
}

/*!
	@brief	Sinus of two vectors.
	@param	a	First vector.
	@param	b	Second vector.
	@return	The sinus of two vectors.
	@note	The sinus of two vectors can be found by dividing by finding the
			inverse of the cosinus of the two vectors.
*/
double	v_sin(t_coords a, t_coords b)
{
	return (sqrt(1 - pow(v_cos(a, b), 2)));
}

/*!
	@brief	Scale a vector.
	@param	a	The vector.
	@param	n	The scale.
	@return	The scaled vector.
	@note	The scaled vector is found by multiplying each component of the
			vector by the scale.
*/
t_coords	v_scale(t_coords a, double n)
{
	t_coords	scale;

	scale.x = a.x * n;
	scale.y = a.y * n;
	scale.z = a.z * n;
	return (scale);
}
