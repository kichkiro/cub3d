/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:54:13 by anvannin          #+#    #+#             */
/*   Updated: 2023/07/07 18:56:57 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

float	distance_between(t_coords a, t_coords b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2)));
}
