/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:04:19 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 07:37:58 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "data.h"
# include "win.h"
# include "macros.h"

/*
** Calc FDF
*/

int						get_set_color(t_block *color, int height,
							int min, int max);
int						get_color(int nb, int start, int end, int diff);
void					set_rgb(t_data *data);
void					move_field(t_data *data);
void					reset_moves(t_data *data);
void					move_block_rgb(t_data *data, int x, int *btn);
int						cursor_in_square(t_coord pos, t_coord size,
							int x, int y);
void					get_dir(t_coord *dir, t_data *data);
void					get_print_order(t_data *data, int pos, t_coord *curr,
							t_coord *next);
int						get_point(t_coord *point, int x, int y, t_data *data);

/*
** initialisation
*/

int						check_file(char **file, int height, int *lenght);
void					init_data(t_data *data);
void					init_ext_height(int *min, int *max, t_field field);

/*
** mlx_functions
*/

int						loop_hook(t_data *data);
int						mouse_hook(int x, int y, t_data *data);
int						key_hook(int keycode, t_data *data);
int						mouse_press_hook(int button, int x, int y,
							t_data *data);
int						mouse_release_hook(int button, int x, int y,
							t_data *data);

/*
** print_fdf
*/

void					print_in_frame(t_data *data);
void					print_field(t_field field, t_img img, t_data *data);
void					print_full_field(t_field field, t_img img,
							t_data *data);
void					print_ex_frame(t_data *data);
void					print_panel(t_data *data);
void					print_sep_panel(t_data *data, int pos_y);
void					print_rotation(t_data *data);
void					print_hills(t_data *data);
void					print_status(t_data *data);
void					print_colors(t_data *data);
void					print_set(t_data *data);

/*
** print_tools
*/

void					print_square(t_coord pos, t_coord size, int color,
							t_img img);
void					print_polygone(t_poly poly, t_img img);
int						put_pxl_img(t_coord coord, t_img img);
void					print_line(t_coord a, t_coord b, t_img img);

/*
** tools
*/

int						put_err(char *str);
int						get_map(char *name, t_field *field);
int						init_mlx(t_data *data);
int						ft_abs(int nb);
void					ft_swap(int *a, int *b);
int						get_value(char c, char *base);
int						get_nbr(char *str, char *base);
int						ft_strlen(char *str);

#endif
