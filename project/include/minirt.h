/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:00:19 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/02 19:22:41 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// Libraries ------------------------------------------------------------------>

# include "../lib/libft/include/libft.h"
# include "../lib/libmlx/include/mlx.h"
# include "../lib/libvec3/include/vec3.h"
# include "parser.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>

// Defines -------------------------------------------------------------------->

// Window -------------------------------------------------------------------->>

# define WIN_WIDTH 		1917
# define WIN_HEIGHT 	987

// Colors -------------------------------------------------------------------->>

# define HEX_WHITE 		0x00FFFFFF
# define HEX_BLACK 		0x00000000
# define HEX_RED 		0x00FF0000
# define HEX_GREEN 		0x0000FF00
# define HEX_BLUE 		0x000000FF
# define HEX_YELLOW 	0x00FFFF00
# define HEX_MAGENTA 	0x00FF00FF
# define HEX_CYAN 		0x0000FFFF

// Structures ----------------------------------------------------------------->

typedef struct s_rgb	t_rgb;
typedef struct s_sphere	t_sphere;
typedef struct s_scene	t_scene;

typedef struct s_img100
{
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_img100;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img100	img;
}	t_mlx;

// Functions ------------------------------------------------------------------>

// main ---------------------------------------------------------------------->>

// void    initializer(t_mlx **mlx);
void    validator(int argc, char **argv);
void	errors_handler(char *msg, t_mlx *mlx, t_scene **scene);
void	terminator(t_scene **scene, t_mlx *mlx);

// visualizator -------------------------------------------------------------->>

void	visualizator(t_mlx *mlx);
void	window_init(t_mlx **mlx);
void	my_pixel_put(t_img100 img, int x, int y, int color);
int		mlx_exit(t_mlx *mlx);
void	window_destroy(t_mlx *mlx);
void	window_labels(t_mlx *mlx);
int		key_hook(int keycode, t_mlx *mlx);
int		mouse_hooks(int key, int x, int y, t_mlx *mlx);
void	log_sphere(t_sphere *sph);

#endif
