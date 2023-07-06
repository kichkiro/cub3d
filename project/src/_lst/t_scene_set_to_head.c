/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_scene_set_to_head.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:08:36 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/06 14:10:31 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	t_scene_set_to_head(t_scene **scene)
{
	while (scene && *scene && (*scene)->prev)
		*scene = (*scene)->prev;
}
