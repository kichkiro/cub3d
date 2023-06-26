/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:00:19 by kichkiro          #+#    #+#             */
/*   Updated: 2023/06/26 19:54:58 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// Libraries ------------------------------------------------------------------>

# include "../lib/libft.h"
# include "../lib/libmlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <math.h>

# define WIN_WIDTH 500
# define WIN_HEIGHT 500

# define ESCAPE 0xff1b

// Structures ----------------------------------------------------------------->
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}t_mlx;

// Functions ------------------------------------------------------------------>

// window.c ------------------------------------------------------------------->
int	window_init(t_mlx *mlx);

// hooks.c -------------------------------------------------------------------->
int	hooks_init(t_mlx *mlx);

#endif
