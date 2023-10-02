/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:59:30 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/02 19:26:15 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"

int	main(int argc, char **argv)
{
	t_scene	*scene;
	t_mlx	*mlx;

	validator(argc, argv);
	parser(argv[1], &scene);
	window_init(&mlx);
	render(&mlx, scene);
	visualizator(mlx);
	terminator(&scene, mlx);
	return (0);
}
