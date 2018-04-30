/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:41:36 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 07:43:15 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		init_move(t_data *data)
{
	data->move.prev_x = 10000;
	data->move.prev_y = 10000;
	data->move.right = 0;
	data->move.left = 0;
	data->move.bot = 0;
	data->move.top = 0;
	data->action.move = 0;
}

void		init_action(t_data *data)
{
	data->action.move = 0;
	data->action.color_block = -1;
	data->action.hill = 0;
	data->action.rot = 0;
	data->action.move_r = 0;
	data->action.move_g = 0;
	data->action.move_b = 0;
}

void		init_data(t_data *data)
{
	init_move(data);
	init_action(data);
	data->input.left_button = RELEASED;
	data->pos.x_angle = 0.0;
	data->pos.y_angle = 0.0;
	data->pos.z_angle = 0.0;
	data->rot = RO_POS_X;
	data->pos.zoom = (data->field.height > data->field.lenght) ?
		((double)I_FRAME_HEIGHT / (double)data->field.height) :
	((double)I_FRAME_LENGHT / (double)data->field.lenght);
	data->move.prev_x = 10000;
	data->move.prev_y = 10000;
	data->status = WIRE;
	data->hill.percent = 100;
	data->hill.pos = HILL_POS_X + HILL_LENGHT / 2 - H_BLOCK_LENGHT / 2;
	data->color_param = SOURCE_COLOR;
	data->rgb.set = 0;
	data->pos.zoom_max = data->pos.zoom * 5.0;
	data->pos.zoom_min = data->pos.zoom / 10.0;
}
