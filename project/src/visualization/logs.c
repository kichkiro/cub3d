/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:13:53 by anvannin          #+#    #+#             */
/*   Updated: 2023/09/30 11:45:13 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"

void	log_sphere(t_sphere *sph)
{
	int	left;
	int	right;
	int	top;
	int	bottom;

	left = (int)(sph->coords->x - sph->diameter / 2) + WIN_HEIGHT / 2;
	right = (int)(sph->coords->x + sph->diameter / 2) + WIN_HEIGHT / 2;
	top = (int)(sph->coords->y - sph->diameter / 2) + WIN_WIDTH / 2;
	bottom = (int)(sph->coords->y + sph->diameter / 2) + WIN_WIDTH / 2;
	printf("---------------------------SPHERE---------------------------\n");
	printf("x: %f\ty: %f\tz: %f\n", sph->coords->x, sph->coords->y,
		sph->coords->z);
	printf("radius: %f\tdiameter:%f\n", sph->diameter / 2, sph->diameter);
	printf("color: ");
	print_rgb_hex(sph->rgb);
	printf("center: [%d, %d]\n", (int)sph->coords->x + WIN_HEIGHT / 2,
		(int)sph->coords->y + WIN_WIDTH / 2);
	printf("\nleft: [%d, %d], right: [%d, %d]\n", left, WIN_HEIGHT / 2, right,
		WIN_HEIGHT / 2);
	printf("top: [%d, %d], bottom: [%d, %d]\n", top, WIN_WIDTH / 2, bottom,
		WIN_WIDTH / 2);
	printf("------------------------------------------------------------\n");
}
