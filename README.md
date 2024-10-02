<img src="https://github.com/kichkiro/42_cursus/blob/assets/banner_minirt.png?raw=true" width="100%"/>

# MiniRT

<i>
  <p>
    When it comes to rendering 3-dimensional computer-generated images there are 2 possible approaches: “Rasterization”, which is used by almost all graphic engines because of its efficiency and “Ray Tracing.”
  </p>
  <p>
	The “Ray Tracing” method, developed for the first time in 1968 (but improved upon since) is even today more expensive in computation than the “Rasterization” method.
	<br>
	As a result, it is not yet fully adapted to real time use-cases but it produce a much higher degree of visual realism.
  </p>
  <p>
   Before you can even begin to produce such high-quality graphics, you must master the basics: the miniRT is your first ray tracer coded in C, normed and humble but functionnal.
  </p>
  <p>
	The main goal of miniRT is to prove to yourself that you can implement any mathematics or physics formulas without being a mathematician, we will only implement the most basics ray tracing features here so just keep calm, take a deep breath and don’t panic!
	<br>
	After this project you’ll be able to show off nice-looking pictures to justify the number of hours you’re spending at school...
  </p>
</i>

#### <i>[subject](_subject/en.subject.pdf) v.7.2</i>

<details>
<summary><i><b>Project Structure  📂</b></i></summary>

``` js
├── Dockerfile
├── LICENSE
├── README.md
├── project
│   ├── Makefile
│   ├── TODO.md
│   ├── include
│   │   ├── minirt.h
│   │   ├── parser.h
│   │   └── render.h
│   ├── lib
│   │   ├── libft
│   │   │   ├── Makefile
│   │   │   ├── include
│   │   │   │   └── libft.h
│   │   │   └── src
│   │   │       ├── algo
│   │   │       │   ├── ft_lds.c
│   │   │       │   └── ft_lis.c
│   │   │       ├── fd
│   │   │       │   ├── ft_exit.c
│   │   │       │   ├── ft_putchar_fd.c
│   │   │       │   ├── ft_putendl_fd.c
│   │   │       │   ├── ft_putnbr_fd.c
│   │   │       │   └── ft_putstr_fd.c
│   │   │       ├── _get_next_line
│   │   │       │   └── ft_get_next_line.c
│   │   │       ├── hex
│   │   │       │   ├── ft_hexlen.c
│   │   │       │   ├── ft_ultoa_hex.c
│   │   │       │   └── ft_utoa_hex.c
│   │   │       ├── is
│   │   │       │   ├── ft_isalnum.c
│   │   │       │   ├── ft_isalpha.c
│   │   │       │   ├── ft_isascii.c
│   │   │       │   ├── ft_isdigit.c
│   │   │       │   └── ft_isprint.c
│   │   │       ├── mem
│   │   │       │   ├── ft_bzero.c
│   │   │       │   ├── ft_calloc.c
│   │   │       │   ├── ft_free.c
│   │   │       │   ├── ft_memchr.c
│   │   │       │   ├── ft_memcmp.c
│   │   │       │   ├── ft_memcpy.c
│   │   │       │   ├── ft_memmove.c
│   │   │       │   └── ft_memset.c
│   │   │       ├── _printf
│   │   │       │   ├── ft_printf_assembly_line.c
│   │   │       │   ├── ft_printf.c
│   │   │       │   ├── ft_printf_format.c
│   │   │       │   └── lst
│   │   │       │       ├── t_print_add_back.c
│   │   │       │       ├── t_print_add_front.c
│   │   │       │       ├── t_print_add_inside.c
│   │   │       │       ├── t_print_del_last.c
│   │   │       │       ├── t_print_last.c
│   │   │       │       ├── t_print_new.c
│   │   │       │       ├── t_print_size.c
│   │   │       │       └── t_print_split_str.c
│   │   │       └── str
│   │   │           ├── ft_atof.c
│   │   │           ├── ft_atoi.c
│   │   │           ├── ft_char_append.c
│   │   │           ├── ft_itoa.c
│   │   │           ├── ft_n_is_in_arr.c
│   │   │           ├── ft_split.c
│   │   │           ├── ft_split_substr.c
│   │   │           ├── ft_strappend.c
│   │   │           ├── ft_strchr.c
│   │   │           ├── ft_strdup.c
│   │   │           ├── ft_stridx.c
│   │   │           ├── ft_striteri.c
│   │   │           ├── ft_strjoin.c
│   │   │           ├── ft_strlcat.c
│   │   │           ├── ft_strlcpy.c
│   │   │           ├── ft_strlen.c
│   │   │           ├── ft_strmapi.c
│   │   │           ├── ft_strmatrixfree.c
│   │   │           ├── ft_strmatrixjoin.c
│   │   │           ├── ft_strmatrixlen.c
│   │   │           ├── ft_strncmp.c
│   │   │           ├── ft_strnstr.c
│   │   │           ├── ft_strrchr.c
│   │   │           ├── ft_strrev.c
│   │   │           ├── ft_strtrim.c
│   │   │           ├── ft_substr.c
│   │   │           ├── ft_tolower.c
│   │   │           ├── ft_toupper.c
│   │   │           └── ft_utoa.c
│   │   ├── libmlx
│   │   │   ├── Makefile
│   │   │   ├── include
│   │   │   │   ├── mlx.h
│   │   │   │   └── mlx_int.h
│   │   │   └── src
│   │   │       ├── mlx_clear_window.c
│   │   │       ├── mlx_destroy_display.c
│   │   │       ├── mlx_destroy_image.c
│   │   │       ├── mlx_destroy_window.c
│   │   │       ├── mlx_expose_hook.c
│   │   │       ├── mlx_ext_randr.c
│   │   │       ├── mlx_flush_event.c
│   │   │       ├── mlx_get_color_value.c
│   │   │       ├── mlx_get_data_addr.c
│   │   │       ├── mlx_hook.c
│   │   │       ├── mlx_init.c
│   │   │       ├── mlx_int_anti_resize_win.c
│   │   │       ├── mlx_int_deal_shm.c
│   │   │       ├── mlx_int_do_nothing.c
│   │   │       ├── mlx_int_get_visual.c
│   │   │       ├── mlx_int_param_event.c
│   │   │       ├── mlx_int_rgb_conversion.c
│   │   │       ├── mlx_int_set_win_event_mask.c
│   │   │       ├── mlx_int_str_to_wordtab.c
│   │   │       ├── mlx_int_wait_first_expose.c
│   │   │       ├── mlx_key_hook.c
│   │   │       ├── mlx_lib_xpm.c
│   │   │       ├── mlx_loop.c
│   │   │       ├── mlx_loop_hook.c
│   │   │       ├── mlx_mouse.c
│   │   │       ├── mlx_mouse_hook.c
│   │   │       ├── mlx_new_image.c
│   │   │       ├── mlx_new_window.c
│   │   │       ├── mlx_pixel_put.c
│   │   │       ├── mlx_put_image_to_window.c
│   │   │       ├── mlx_rgb.c
│   │   │       ├── mlx_screen_size.c
│   │   │       ├── mlx_set_font.c
│   │   │       ├── mlx_string_put.c
│   │   │       └── mlx_xpm.c
│   │   └── libvec3
│   │       ├── Makefile
│   │       ├── include
│   │       │   └── vec3.h
│   │       └── src
│   │           ├── vec3_adv.c
│   │           ├── vec3_basic2.c
│   │           ├── vec3_basic.c
│   │           ├── vec3_normalize.c
│   │           ├── vec3_pointer.c
│   │           ├── vec3_rot.c
│   │           └── vec3_trig.c
│   ├── scenes
│   │   ├── cylinders.rt
│   │   ├── e_ambient_range.rt
│   │   ├── e_capitalize.rt
│   │   ├── e_direction.rt
│   │   ├── e_invalid_identifier.rt
│   │   ├── e_missing_args.rt
│   │   ├── e_rgb.rt
│   │   ├── e_too_many_args.rt
│   │   ├── let_there_be_light.rt
│   │   ├── mickey.rt
│   │   ├── multi_obj_shadow.rt
│   │   └── test.rt
│   └── src
│       ├── log
│       │   ├── log_hooks.c
│       │   └── log_obj.c
│       ├── _lst
│       │   ├── t_scene_add_back.c
│       │   ├── t_scene_check_unique.c
│       │   ├── t_scene_free.c
│       │   ├── t_scene_get_obj.c
│       │   ├── t_scene_new.c
│       │   └── t_scene_set_to_head.c
│       ├── main
│       │   ├── errors_handler.c
│       │   ├── initializer.c
│       │   ├── main.c
│       │   ├── terminator.c
│       │   └── validator.c
│       ├── parsing
│       │   ├── camera.c
│       │   ├── geometric_obj.c
│       │   ├── get_value.c
│       │   ├── lighting_obj.c
│       │   └── parser.c
│       ├── rendering
│       │   ├── color2.c
│       │   ├── color.c
│       │   ├── intersec_cylinder.c
│       │   ├── intersections.c
│       │   ├── lighting.c
│       │   ├── raycaster.c
│       │   └── render.c
│       ├── transform
│       │   ├── rotate.c
│       │   ├── scale.c
│       │   └── traslate.c
│       └── visualization
│           ├── hooks.c
│           ├── visualizator.c
│           └── window_labels.c
└── _subject
    ├── en.subject.pdf
    ├── minilibx-linux.tgz
    ├── minilibx_mms_20200219_beta.tgz
    └── minilibx_opengl.tgz
```
</details>

## 📌 - Key Topics
### Ray Tracing 
Ray tracing is the primary rendering technique in this project, involving the simulation of light paths to generate realistic images. The project requires implementing basic ray-object intersection algorithms for geometric shapes like spheres, planes, and cylinders, as well as handling ambient lighting, shadows, and reflections.

## 🛠️ - Usage

```
git clone https://github.com/kichkiro/miniRT.git
cd miniRT/
```
---TODO---

## ⚖️ - License

See [LICENSE](LICENSE)
