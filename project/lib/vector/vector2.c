/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:56:00 by anvannin          #+#    #+#             */
/*   Updated: 2023/07/28 19:18:37 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*!
	@brief	Module of a vector.
	@param	a	The vector.
	@return	The module of the vector.
*/
double	v_module(t_coords a)
{
	return (sqrt(v_dot_product(a, a)));
}
