/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:59:30 by kichkiro          #+#    #+#             */
/*   Updated: 2023/09/07 12:10:54 by kichkiro         ###   ########.fr       */
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
	printf("id = %d\n", t_scene_find_obj_by_id(scene, 4)->id);
	mlx = (t_mlx *)ft_calloc(sizeof(t_mlx), 1);
	window_init(mlx);
	render(mlx, scene);
	hooks_init(mlx);
	free_all(&scene, mlx);
	return (0);
}
