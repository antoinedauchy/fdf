/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 20:07:44 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 04:20:37 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		print_rotation(t_data *data)
{
	t_coord	pos;
	t_coord	size;

	print_sep_panel(data, ROT_POS_Y + ROT_HEIGHT - HGT_SEP_PANEL);
	size.x = ROT_LENGHT / 5;
	size.y = ROT_LENGHT / 5;
	pos.x = ROT_POS_X + ROT_LENGHT / 12;
	pos.y = ROT_POS_Y + (ROT_HEIGHT - HGT_SEP_PANEL) / 2 - size.y / 2;
	print_square(pos, size, 0, data->img);
	pos.x = RO_POS_X;
	pos.y = RO_POS_Y;
	size.x = RO_LENGHT;
	size.y = RO_HEIGHT;
	print_square(pos, size, 0xA5A5A5, data->img);
	pos.x = data->rot;
	size.x = R_BLOCK_LENGHT;
	print_square(pos, size, 0x333333, data->img);
}
