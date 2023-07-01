/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:00:19 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/01 17:18:28 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// Libraries ------------------------------------------------------------------>

# include "../lib/libft.h"
# include "../lib/libmlx.h"
# include "parser.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <math.h>

// Defines -------------------------------------------------------------------->

# define WIN_WIDTH 500
# define WIN_HEIGHT 500

# define ESCAPE 0xff1b

// Structures ----------------------------------------------------------------->

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}	t_mlx;

// Linked Lists --------------------------------------------------------------->

typedef struct s_scene
{
	char			id;
	bool			unique;
	void			*data;
	struct s_scene	*prev;
	struct s_scene	*next;
}	t_scene;

t_scene		*t_scene_new(char id, bool unique, void *data);
void		t_scene_add_back(t_scene **lst, t_scene *new);

// Functions ------------------------------------------------------------------>

//ft_atof.c ---> add to libft ------------------------------------------------->
double	ft_atof(char *s);

// window.c ------------------------------------------------------------------->
int		window_init(t_mlx *mlx);

// hooks.c -------------------------------------------------------------------->
int		hooks_init(t_mlx *mlx);

// utils.c -------------------------------------------------------------------->
void	ft_fatal(char *msg);

#endif
