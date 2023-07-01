/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:59:30 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/01 17:13:24 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_scene	*scene;
	t_mlx	*mlx;

	if (argc != 2)
	{
		ft_putstr_fd(YELLOW"usage: ./minirt <path_scene>.rt\n"RESET, 2);
		return (1);
	}
	scene = get_scene(argv[1]);
	mlx = (t_mlx *)ft_calloc(sizeof(t_mlx), 1);
	window_init(mlx);
	hooks_init(mlx);
	return (0);
}
