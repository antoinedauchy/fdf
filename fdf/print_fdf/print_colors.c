/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 22:11:09 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 04:20:19 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			print_colors(t_data *data)
{
	t_coord		pos;
	t_coord		size;
	int			n;
	int			color;

	pos.x = BLOCK_POS_X;
	pos.y = COLORS_POS_Y;
	size.x = BLOCK_LENGHT;
	size.y = COLORS_HEIGHT;
	print_sep_panel(data, COLORS_POS_Y + COLORS_HEIGHT);
	print_square(pos, size, 0xA5A5A5, data->img);
	size.y = BLOCK_HEIGHT;
	n = 0;
	while (n < 3)
	{
		color = data->color[n].color;
		pos.y = data->color[n].pos;
		if (data->color[n].status)
			print_square(pos, size, color, data->img);
		n++;
	}
}
