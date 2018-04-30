/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sep_panel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 21:03:15 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 04:20:41 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		print_sep_panel(t_data *data, int pos_y)
{
	t_coord		pos;
	t_coord		size;

	pos.x = ROT_POS_X;
	pos.y = pos_y;
	size.x = ROT_LENGHT;
	size.y = HGT_SEP_PANEL;
	print_square(pos, size, 0, data->img);
}
