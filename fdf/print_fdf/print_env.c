/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 22:51:47 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 04:48:44 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			print_panel(t_data *data)
{
	t_coord		size;
	t_coord		pos;

	pos.x = PANEL_POS_X;
	pos.y = PANEL_POS_Y;
	size.x = PANEL_LENGHT;
	size.y = PANEL_HEIGHT;
	print_square(pos, size, 0x888888, data->img);
	print_rotation(data);
	print_hills(data);
	print_status(data);
	print_colors(data);
	print_set(data);
}

void			print_in_frame(t_data *data)
{
	t_coord		size;
	t_coord		pos;

	pos.x = I_FRAME_POS_X;
	pos.y = I_FRAME_POS_Y;
	size.x = I_FRAME_LENGHT;
	size.y = I_FRAME_HEIGHT;
	print_square(pos, size, 0, data->img);
}

void			print_ex_frame(t_data *data)
{
	t_coord		size;
	t_coord		pos;

	pos.x = E_FRAME_POS_X;
	pos.y = E_FRAME_POS_Y;
	size.x = E_FRAME_LENGHT;
	size.y = HEIGHT_FRAME;
	print_square(pos, size, 0x444444, data->img);
	pos.y = HEIGHT_WIN - HEIGHT_FRAME;
	print_square(pos, size, 0x444444, data->img);
	pos.y = HEIGHT_FRAME;
	size.x = LENGHT_FRAME;
	size.y = I_FRAME_HEIGHT;
	print_square(pos, size, 0x444444, data->img);
	pos.x = LENGHT_WIN - LENGHT_FRAME;
	print_square(pos, size, 0x444444, data->img);
}
