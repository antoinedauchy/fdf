/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 23:08:33 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 04:19:22 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		move_block_color(t_data *data, int y, int n)
{
	int		new_pos;
	int		size;
	int		diff;

	diff = data->action.y - data->color[n].pos;
	new_pos = y - diff;
	size = COLORS_HEIGHT - BLOCK_HEIGHT;
	data->color[n].pos = new_pos;
	data->action.y = y;
	if (n < 2 && new_pos < data->color[n + 1].pos + BLOCK_HEIGHT)
		data->color[n].pos = data->color[n + 1].pos + BLOCK_HEIGHT;
	else if (new_pos < COLORS_POS_Y)
		data->color[n].pos = COLORS_POS_Y;
	if (n > 0 && new_pos > data->color[n - 1].pos - BLOCK_HEIGHT)
		data->color[n].pos = data->color[n - 1].pos - BLOCK_HEIGHT;
	else if (new_pos > COLORS_POS_Y + size)
		data->color[n].pos = COLORS_POS_Y + size;
	if (data->color[n].pos == COLORS_POS_Y ||
		data->color[n].pos == COLORS_POS_Y + size ||
		(n < 2 && new_pos < data->color[n + 1].pos + BLOCK_HEIGHT) ||
		(n > 0 && new_pos > data->color[n - 1].pos - BLOCK_HEIGHT))
		data->action.y = data->color[n].pos + diff;
	data->color[n].percent = 100 * (size -
		data->color[n].pos + COLORS_POS_Y) / size;
}

void		move_block_hill(t_data *data, int x)
{
	int		new_pos;
	int		diff;
	int		size;

	diff = data->action.x - data->hill.pos;
	new_pos = x - diff;
	size = HILL_LENGHT - H_BLOCK_LENGHT;
	if (new_pos < HILL_POS_X)
		data->hill.pos = HILL_POS_X;
	else if (new_pos > HILL_POS_X + size)
		data->hill.pos = HILL_POS_X + size;
	else
	{
		data->hill.pos = new_pos;
		data->action.x = x;
	}
	if (data->hill.pos == HILL_POS_X || data->hill.pos == HILL_POS_X + size)
		data->action.x = data->hill.pos + diff;
	data->hill.percent = 200 * (data->hill.pos - HILL_POS_X) /
		(HILL_LENGHT - H_BLOCK_LENGHT);
}

void		move_block_rot(t_data *data, int x)
{
	int		new_pos;
	int		diff;
	int		size;

	diff = data->action.x - data->rot;
	new_pos = x - diff;
	size = RO_LENGHT - R_BLOCK_LENGHT;
	if (new_pos < RO_POS_X)
		data->rot = RO_POS_X;
	else if (new_pos > RO_POS_X + size)
		data->rot = RO_POS_X + size;
	else
	{
		data->rot = new_pos;
		data->action.x = x;
	}
	if (data->rot == RO_POS_X || data->rot == RO_POS_X + size)
		data->action.x = data->rot + diff;
	data->pos.z_angle = 360 * (data->rot - RO_POS_X) /
		(RO_LENGHT - R_BLOCK_LENGHT);
}

void		get_moves(int x, int y, t_data *data)
{
	if (data->move.prev_x != 10000 && data->move.prev_y != 10000)
	{
		if (x > data->move.prev_x)
			data->move.right = x - data->move.prev_x;
		else if (x < data->move.prev_x)
			data->move.left = data->move.prev_x - x;
		if (y > data->move.prev_y)
			data->move.bot = y - data->move.prev_y;
		else if (y < data->move.prev_y)
			data->move.top = data->move.prev_y - y;
	}
	data->move.prev_x = x;
	data->move.prev_y = y;
}

int			mouse_hook(int x, int y, t_data *data)
{
	if (data->input.left_button == PRESSED)
	{
		get_moves(x, y, data);
		if (data->action.color_block != -1)
			move_block_color(data, y, data->action.color_block);
		if (data->action.hill)
			move_block_hill(data, x);
		if (data->action.rot)
			move_block_rot(data, x);
		if (data->action.move_r)
			move_block_rgb(data, x, &data->rgb.pos_r);
		else if (data->action.move_g)
			move_block_rgb(data, x, &data->rgb.pos_g);
		else if (data->action.move_b)
			move_block_rgb(data, x, &data->rgb.pos_b);
	}
	return (0);
}
