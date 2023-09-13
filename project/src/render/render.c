/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:40:50 by anvannin          #+#    #+#             */
/*   Updated: 2023/09/13 08:49:45 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*!
 * @brief 
	Renders a sky gradient.
	Calculates the blend value for the pixel and sets the pixel color to the 
	blend value.
 * @param mlx 
	A pointer to mlx structure.
 * @param win_x 
	The x-coordinate of window.
 * @param win_y 
	The y coordinate of window.
 */
void	render_sky_gradient(t_mlx *mlx, int win_x, int win_y)
{
	int		blend_value;
	double	t;

	t = (double)win_y / ((double)WIN_HEIGHT - 1);
	blend_value = (int)(t * 255.999);
	my_pixel_put(mlx->img, win_x, win_y,
		rgb_to_int2(blend_value, blend_value, 255));
}

/*!
 * @brief 
	This function renders a white center cross on the screen. It draws a cross
	shape at the center of the window for reference or visualization purposes.
 * @param mlx 
	A pointer to mlx structure.
 */
static void	render_center_cross(t_mlx *mlx)
{
	int	y;
	int	i;

	i = -1;
	my_pixel_put(mlx->img, WIN_WIDTH / 2, WIN_HEIGHT / 2, HEX_WHITE);
	while (++i < 5)
	{
		my_pixel_put(mlx->img, WIN_WIDTH / 2, WIN_HEIGHT / 2 + i, HEX_WHITE);
		my_pixel_put(mlx->img, WIN_WIDTH / 2, WIN_HEIGHT / 2 - i, HEX_WHITE);
		my_pixel_put(mlx->img, WIN_WIDTH / 2 + i, WIN_HEIGHT / 2, HEX_WHITE);
		my_pixel_put(mlx->img, WIN_WIDTH / 2 - i, WIN_HEIGHT / 2, HEX_WHITE);
	}
}

/*!
 * @brief 
	This function renders the entire scene, including objects and additional 
	visual elements, on the screen. 
 	It also displays labels and text within the window.
 * @param mlx 
	A pointer to mlx structure.
 * @param scene 
	A pointer to the scene linked list that contains scene objects.
 */
void	render(t_mlx *mlx, t_scene *scene)
{
	render_sphere(mlx, scene);
	render_center_cross(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	window_labels(mlx);
}
