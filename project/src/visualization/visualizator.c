/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:43:32 by kichkiro          #+#    #+#             */
/*   Updated: 2023/09/28 10:46:54 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	visualizator(t_mlx *mlx)
{
	mlx_do_key_autorepeaton(mlx->mlx_ptr);
	mlx_hook(mlx->win_ptr, 17, 1L << 17, mlx_exit, mlx);
	mlx_hook(mlx->win_ptr, 2, 1l << 0, &key_hook, mlx);
	mlx_mouse_hook(mlx->win_ptr, &mouse_hooks, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (1);
}
