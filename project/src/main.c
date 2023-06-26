/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:59:30 by kichkiro          #+#    #+#             */
/*   Updated: 2023/06/26 20:55:09 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)calloc(sizeof(t_mlx), 1);
	window_init(mlx);
	hooks_init(mlx);
	return (0);
}
