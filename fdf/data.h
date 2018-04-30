/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 07:33:45 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 07:48:00 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

/*
** Minilibx images
*/

typedef struct			s_img
{
	void				*img;
	char				*data;
	int					bpb;
	int					sizeline;
	int					endian;
	int					height;
	int					lenght;
}						t_img;

/*
** Field definition
*/

typedef struct			s_point
{
	int					height;
	int					color;
	int					z;
}						t_point;

typedef struct			s_field
{
	t_point				**map;
	int					lenght;
	int					height;
}						t_field;

/*
** Input actions
*/

typedef struct			s_move
{
	int					right;
	int					left;
	int					top;
	int					bot;
	int					prev_x;
	int					prev_y;
}						t_move;

typedef struct			s_pos
{
	double				x_angle;
	double				y_angle;
	double				z_angle;
	double				zoom;
	double				zoom_max;
	double				zoom_min;
}						t_pos;

typedef struct			s_action
{
	int					move;
	int					color_block;
	int					hill;
	int					rot;
	int					x;
	int					y;
	int					move_r;
	int					move_g;
	int					move_b;
}						t_action;

typedef struct			s_input
{
	int					left_button;
}						t_input;

/*
** Positions in window
*/

typedef struct			s_block
{
	int					percent;
	int					color;
	int					status;
	int					pos;
}						t_block;

typedef struct			s_coord
{
	int					x;
	int					y;
	int					color;
}						t_coord;

typedef struct			s_rgb
{
	int					r;
	int					pos_r;
	int					g;
	int					pos_g;
	int					b;
	int					pos_b;
	int					set;
}						t_rgb;

/*
** Global data
*/

typedef struct			s_data
{
	t_field				field;
	void				*mlx;
	void				*win;
	t_input				input;
	t_img				img;
	t_move				move;
	t_pos				pos;
	t_action			action;
	t_block				*color;
	t_block				hill;
	int					rot;
	int					wesh;
	int					status;
	int					color_param;
	int					min_height;
	int					max_height;
	t_rgb				rgb;
	t_coord				dir;
}						t_data;

/*
** Calcul tools
*/

typedef struct			s_poly
{
	t_coord				a;
	t_coord				b;
	t_coord				c;
	t_coord				d;
}						t_poly;

typedef struct			s_line
{
	int					dist_x;
	int					dist_y;
	int					dist;
	int					nb;
}						t_line;

#endif
