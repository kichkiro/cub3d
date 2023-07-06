/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:59:30 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/06 12:36:42 by kichkiro         ###   ########.fr       */
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
		return (error_message("usage"));
	scene = get_scene(argv[1]);
	mlx = (t_mlx *)ft_calloc(sizeof(t_mlx), 1);
	window_init(mlx);
	hooks_init(mlx);
	free_all(&scene, mlx);
	return (0);
}
