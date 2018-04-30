/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_block_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 23:01:08 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 07:22:32 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		modify_color(int *color, char part, int pos)
{
	int		col;

	col = (pos - SET_WAY_POS_X) * 255 / (SET_WAY_LGT - SET_BTN_LGT);
	if (part == 'r')
		*color = col * 0x10000 + *color % 0x10000;
	else if (part == 'g')
		*color = *color / 0x10000 * 0x10000 + col * 0x100 + *color % 0x100;
	else
		*color = *color / 0x100 * 0x100 + col;
}

void		move_block_rgb(t_data *data, int x, int *btn)
{
	int		new_pos;
	int		diff;
	int		size;

	diff = data->action.x - *btn;
	new_pos = x - diff;
	size = SET_WAY_LGT - SET_BTN_LGT;
	if (new_pos < SET_WAY_POS_X)
		*btn = SET_WAY_POS_X;
	else if (new_pos > SET_WAY_POS_X + size)
		*btn = SET_WAY_POS_X + size;
	else
	{
		*btn = new_pos;
		data->action.x = x;
	}
	if (*btn == SET_WAY_POS_X || *btn == SET_WAY_POS_X + size)
		data->action.x = *btn + diff;
	if (data->action.move_r)
		modify_color(&data->color[data->rgb.set].color, 'r', *btn);
	else if (data->action.move_g)
		modify_color(&data->color[data->rgb.set].color, 'g', *btn);
	else
		modify_color(&data->color[data->rgb.set].color, 'b', *btn);
}
