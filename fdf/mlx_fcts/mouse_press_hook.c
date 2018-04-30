/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:13:38 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 07:42:59 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		get_color_action(int x, int y, t_data *data)
{
	t_coord	pos;
	t_coord	size;
	int		n;

	pos.x = BLOCK_POS_X;
	size.x = BLOCK_LENGHT;
	size.y = BLOCK_HEIGHT;
	n = 0;
	while (n < 3)
	{
		pos.y = data->color[n].pos;
		if (cursor_in_square(pos, size, x, y))
		{
			data->color_param = SET_COLOR;
			data->action.y = y;
			data->action.color_block = n;
			if (n != data->rgb.set)
			{
				data->rgb.set = n;
				set_rgb(data);
			}
		}
		n++;
	}
}

void		get_status_action(int x, int y, t_data *data)
{
	t_coord		pos;
	t_coord		size;

	pos.y = STAT_BTN_Y;
	size.x = STAT_BTN_LGT;
	size.y = STAT_BTN_HGT;
	pos.x = WIRE_POS_X;
	if (cursor_in_square(pos, size, x, y))
		data->status = WIRE;
	pos.x = POINT_POS_X;
	if (cursor_in_square(pos, size, x, y))
		data->status = POINT;
	pos.x = FULL_POS_X;
	if (cursor_in_square(pos, size, x, y))
		data->status = FULL;
}

void		get_rgb_action(int x, int y, t_data *data)
{
	t_coord		pos;
	t_coord		size;

	pos.x = data->rgb.pos_r;
	pos.y = SET_POS_Y + SET_HEIGHT / 4 - SET_IMG_WDH / 2 + DIFF_BTN_WAY;
	size.x = SET_BTN_LGT;
	size.y = SET_WAY_HGT;
	if (cursor_in_square(pos, size, x, y))
		data->action.move_r = 1;
	pos.x = data->rgb.pos_g;
	pos.y = SET_POS_Y + SET_HEIGHT / 2 - SET_IMG_WDH / 2 + DIFF_BTN_WAY;
	size.x = SET_BTN_LGT;
	size.y = SET_WAY_HGT;
	if (cursor_in_square(pos, size, x, y))
		data->action.move_g = 1;
	pos.x = data->rgb.pos_b;
	pos.y = SET_POS_Y + SET_HEIGHT * 3 / 4 - SET_IMG_WDH / 2 + DIFF_BTN_WAY;
	size.x = SET_BTN_LGT;
	size.y = SET_WAY_HGT;
	if (cursor_in_square(pos, size, x, y))
		data->action.move_b = 1;
}

void		get_action(int x, int y, t_data *data)
{
	t_coord		pos;
	t_coord		size;

	get_color_action(x, y, data);
	get_status_action(x, y, data);
	get_rgb_action(x, y, data);
	pos.x = I_FRAME_POS_X;
	pos.y = I_FRAME_POS_Y;
	size.x = I_FRAME_LENGHT;
	size.y = I_FRAME_HEIGHT;
	if (cursor_in_square(pos, size, x, y))
		data->action.move = 1;
	pos.x = data->hill.pos;
	pos.y = HILL_POS_Y;
	size.x = H_BLOCK_LENGHT;
	size.y = HILL_HEIGHT;
	data->action.x = x;
	if (cursor_in_square(pos, size, x, y))
		data->action.hill = 1;
	pos.x = data->rot;
	pos.y = RO_POS_Y;
	if (cursor_in_square(pos, size, x, y))
		data->action.rot = 1;
}

int			mouse_press_hook(int button, int x, int y, t_data *data)
{
	double	next_zoom;

	if (button == ZOOM_PLUS)
	{
		next_zoom = (data->pos.zoom * ((double)data->field.lenght -
						1.0) * 1.1) / ((double)data->field.lenght - 1.0);
		if (next_zoom <= data->pos.zoom_max)
			data->pos.zoom = next_zoom;
	}
	else if (button == ZOOM_MINUS)
	{
		next_zoom = (data->pos.zoom * ((double)data->field.lenght -
						1.0) * 0.9) / ((double)data->field.lenght - 1.0);
		if (next_zoom >= data->pos.zoom_min)
			data->pos.zoom = next_zoom;
	}
	else if (button == LEFT_BUTTON && y >= 0)
	{
		data->input.left_button = PRESSED;
		get_action(x, y, data);
	}
	return (0);
}
