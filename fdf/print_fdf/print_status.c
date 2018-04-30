/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 21:19:12 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 04:20:51 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			print_status(t_data *data)
{
	t_coord		pos;
	t_coord		size;

	print_sep_panel(data, STAT_POS_Y + STAT_HEIGHT - HGT_SEP_PANEL);
	pos.y = STAT_BTN_Y;
	size.x = STAT_BTN_LGT;
	size.y = STAT_BTN_HGT;
	pos.x = WIRE_POS_X;
	print_square(pos, size, 0, data->img);
	pos.x = POINT_POS_X;
	print_square(pos, size, 0, data->img);
	pos.x = FULL_POS_X;
	print_square(pos, size, 0, data->img);
}
