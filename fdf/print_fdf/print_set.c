/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 22:27:13 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 04:20:46 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		print_rgb(int pos_y, t_data *data, int color, int pos_x)
{
	t_coord	pos;
	t_coord	size;

	(void)data;
	pos.x = SET_IMG_POS_X;
	pos.y = pos_y;
	size.x = SET_IMG_WDH;
	size.y = SET_IMG_WDH;
	print_square(pos, size, color, data->img);
	pos.x = SET_WAY_POS_X;
	pos.y = pos_y + DIFF_BTN_WAY;
	size.x = SET_WAY_LGT;
	size.y = SET_WAY_HGT;
	print_square(pos, size, 0xA5A5A5, data->img);
	pos.x = pos_x;
	size.x = SET_BTN_LGT;
	print_square(pos, size, 0x333333, data->img);
}

void		print_set(t_data *data)
{
	print_rgb(SET_POS_Y + SET_HEIGHT / 4 - SET_IMG_WDH / 2, data, 0xFF0000,
			data->rgb.pos_r);
	print_rgb(SET_POS_Y + SET_HEIGHT / 2 - SET_IMG_WDH / 2, data, 0x00FF00,
			data->rgb.pos_g);
	print_rgb(SET_POS_Y + SET_HEIGHT * 3 / 4 - SET_IMG_WDH / 2, data, 0x0000FF,
			data->rgb.pos_b);
}
