/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:13:53 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/12 21:46:05 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"

void	log_sphere(t_sphere *sp)
{
	int	left;
	int	right;
	int	top;
	int	bottom;

	left = (int)(sp->origin->x - sp->diameter / 2) + WIN_HEIGHT / 2;
	right = (int)(sp->origin->x + sp->diameter / 2) + WIN_HEIGHT / 2;
	top = (int)(sp->origin->y - sp->diameter / 2) + WIN_WIDTH / 2;
	bottom = (int)(sp->origin->y + sp->diameter / 2) + WIN_WIDTH / 2;
	printf("---------------------------SPHERE---------------------------\n");
	printf("x: %f\ty: %f\tz: %f\n", sp->origin->x, sp->origin->y,
		sp->origin->z);
	printf("radius: %f\tdiameter:%f\n", sp->diameter / 2, sp->diameter);
	printf("color: ");
	print_rgb_hex(sp->rgb);
	printf("center: [%d, %d]\n", (int)sp->origin->x + WIN_HEIGHT / 2,
		(int)sp->origin->y + WIN_WIDTH / 2);
	printf("\nleft: [%d, %d], right: [%d, %d]\n", left, WIN_HEIGHT / 2, right,
		WIN_HEIGHT / 2);
	printf("top: [%d, %d], bottom: [%d, %d]\n", top, WIN_WIDTH / 2, bottom,
		WIN_WIDTH / 2);
	printf("------------------------------------------------------------\n");
}

void	log_key_hook(int keycode)
{
	if (keycode == XK_Shift_L)
		printf("shift pressed\n");
	else if (keycode == XK_Control_L)
		printf("control pressed\n");
	else if (keycode == XK_Up)
		printf("up arrow pressed\n");
	else if (keycode == XK_Right)
		printf("right arrow pressed\n");
	else if (keycode == XK_Down)
		printf("down arrow pressed\n");
	else if (keycode == XK_Left)
		printf("left arrow pressed\n");
	else if (keycode == XK_w)
		printf("w pressed\n");
	else if (keycode == XK_s)
		printf("s pressed\n");
	else if (keycode == XK_a)
		printf("a pressed\n");
	else if (keycode == XK_d)
		printf("d pressed\n");
	else if (keycode == XK_q)
		printf("q pressed\n");
	else if (keycode == XK_e)
		printf("e pressed\n");
}

void	log_mouse_hook(int key, int x, int y)
{
	if (key == 1)
		printf("left button pressed: %d %d\n", x, y);
	else if (key == 2)
		printf("right button pressed: %d %d\n", x, y);
	else if (key == 4)
		printf("scroll up\n");
	else if (key == 5)
		printf("scroll down\n");
}
