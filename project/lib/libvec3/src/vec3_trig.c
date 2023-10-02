/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_trig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:56:00 by anvannin          #+#    #+#             */
/*   Updated: 2023/09/30 11:19:07 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

/*!
 * @brief
 	Cosinus of two vectors.
 * @param a
 	First vector.
 * @param b	
	Second vector.
 * @return
	The cosinus of two vectors.
 * @note	
 	The cosinus of two vectors is found by dividing the dot product of the two 
	vectors by the product of their modules.
*/
double	v_cos(t_v3 a, t_v3 b)
{
	return (v_dot_product(a, b) / (v_module(a) * v_module(b)));
}

/*!
 * @brief
 	Sinus of two vectors.
 * @param a
 	First vector.
 * @param b
 	Second vector.
 * @return
 	The sinus of two vectors.
 * @note
 	The sinus of two vectors can be found by dividing by finding the inverse of 
	the cosinus of the two vectors.
*/
double	v_sin(t_v3 a, t_v3 b)
{
	return (sqrt(1 - pow(v_cos(a, b), 2)));
}