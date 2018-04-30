/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hills.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 20:59:50 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 04:20:32 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			print_hills(t_data *data)
{
	t_coord		pos;
	t_coord		size;

	print_sep_panel(data, HILLS_POS_Y + HILLS_HEIGHT - HGT_SEP_PANEL);
	size.x = HILLS_LENGHT / 5;
	size.y = HILLS_LENGHT / 5;
	pos.x = HILLS_POS_X + HILLS_LENGHT / 12;
	pos.y = HILLS_POS_Y + (HILLS_HEIGHT - HGT_SEP_PANEL) / 2 - size.y / 2;
	print_square(pos, size, 0, data->img);
	pos.x = HILL_POS_X;
	pos.y = HILL_POS_Y;
	size.x = HILL_LENGHT;
	size.y = HILL_HEIGHT;
	print_square(pos, size, 0xA5A5A5, data->img);
	pos.x = data->hill.pos;
	size.x = H_BLOCK_LENGHT;
	print_square(pos, size, 0x333333, data->img);
}
