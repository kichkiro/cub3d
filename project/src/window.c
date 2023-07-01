/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:40:10 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/28 14:27:28 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static void	window_labels(t_mlx *mlx)
// {
// 	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, 0x00FFFFFF,
// 		"'ESC': close window");
// }

int	window_init(t_mlx *mlx)
{
	if (!mlx)
		return (0);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (0);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"MiniRT");
	if (!mlx->win_ptr)
		return (0);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!(mlx->img_ptr))
		return (0);
	// window_labels(mlx);
	return (1);
}
