/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:00:19 by kichkiro          #+#    #+#             */
/*   Updated: 2023/09/01 13:47:38 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// Libraries ------------------------------------------------------------------>

# include "../lib/libft/include/libft.h"
# include "../lib/libmlx/include/mlx.h"
# include "../lib/libvec/include/vector.h"
# include "parser.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>

// Defines -------------------------------------------------------------------->

// Window --------------------------------------------------------------------->

# define WIN_WIDTH 1920
# define WIN_HEIGHT 995

// Colors --------------------------------------------------------------------->

# define HEX_WHITE 0x00FFFFFF
# define HEX_BLACK 0x00000000
# define HEX_RED 0x00FF0000
# define HEX_GREEN 0x0000FF00
# define HEX_BLUE 0x000000FF
# define HEX_YELLOW 0x00FFFF00
# define HEX_MAGENTA 0x00FF00FF
# define HEX_CYAN 0x0000FFFF

// Structures ----------------------------------------------------------------->

// References to structs ------------------------------------------------------>
typedef struct s_rgb	t_rgb;
typedef struct s_sphere	t_sphere;

typedef struct s_img100
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img100;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img100	img;
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
void		t_scene_set_to_head(t_scene **scene);
void		t_scene_free(t_scene **scene);

// window.c ------------------------------------------------------------------->
int			window_init(t_mlx *mlx);
void		my_pixel_put(t_img100 img, int x, int y, int color);
int			mlx_exit(t_mlx *mlx);
void		window_destroy(t_mlx *mlx);

// window_labels.c ------------------------------------------------------------>
void		window_labels(t_mlx *mlx);

// hooks.c -------------------------------------------------------------------->
int			hooks_init(t_mlx *mlx);

// keyboard_hooks.c ----------------------------------------------------------->
int			key_hook(int keycode, t_mlx *mlx);

// color.c -------------------------------------------------------------------->
int			rgb_to_int(t_rgb *rgb);
int			rgb_to_int2(int r, int g, int b);
void		print_rgb_int(t_rgb *rgb);
void		print_rgb_hex(t_rgb *rgb);

// render.c ------------------------------------------------------------------->
void		render(t_mlx *mlx, t_scene *scene);
void		render_sky_gradient(t_mlx *mlx, int win_x, int win_y);

// render/sphere.c ------------------------------------------------------------>
void		render_sphere(t_mlx *mlx, t_scene *scene);

// errors_handler.c ----------------------------------------------------------->
void		errors_handler(char *msg, t_mlx *mlx, t_scene **scene);

// logs.c --------------------------------------------------------------------->
void		log_sphere(t_sphere *sph);

#endif
