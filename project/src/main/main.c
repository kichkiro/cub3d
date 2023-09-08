/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:59:30 by kichkiro          #+#    #+#             */
/*   Updated: 2023/09/07 20:13:24 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	check_filename(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (!ft_strncmp(filename + (i - 3), ".rt", 3))
		return (true);
	return (false);
}

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
		errors_handler("usage: ./minirt <path_scene>.rt", NULL, NULL);
	else if (!check_filename(argv[1]))
		errors_handler("invalid filename: it must end with .rt", NULL, NULL);
	scene = get_scene(argv[1]);
	mlx = (t_mlx *)ft_calloc(sizeof(t_mlx), 1);
	window_init(mlx);
	render(mlx, scene);
	hooks_init(mlx);
	free_all(&scene, mlx);
	return (0);
}
