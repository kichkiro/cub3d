/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:59:30 by kichkiro          #+#    #+#             */
/*   Updated: 2023/08/02 20:14:58 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	free_all(t_scene **scene, t_mlx *mlx)
{
	t_scene_free(scene);
	window_destroy(mlx);
}

int	main(int argc, char **argv)
{
	t_scene	*scene;
	t_mlx	*mlx;

	if (argc != 2)
		errors_handler("usage", NULL, NULL);
	scene = get_scene(argv[1]);
	mlx = (t_mlx *)ft_calloc(sizeof(t_mlx), 1);
	window_init(mlx);
	render(mlx, scene);
	hooks_init(mlx);
	free_all(&scene, mlx);
	return (0);
}
