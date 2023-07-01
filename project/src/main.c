/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:59:30 by kichkiro          #+#    #+#             */
/*   Updated: 2023/06/30 18:28:37 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2)
	{
		strerror(1);
		return (1);
	}
	get_scene(argv[1]);

	mlx = (t_mlx *)calloc(sizeof(t_mlx), 1);
	window_init(mlx);
	hooks_init(mlx);

	return (0);
}
