/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 21:57:24 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 04:17:04 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		set_rgb(t_data *data)
{
	data->rgb.pos_r = (data->color[data->rgb.set].color / 0x10000) *
			(SET_WAY_LGT - SET_BTN_LGT) / 0xFF + SET_WAY_POS_X;
	data->rgb.pos_g = (data->color[data->rgb.set].color / 0x100 % 0x100) *
			(SET_WAY_LGT - SET_BTN_LGT) / 0xFF + SET_WAY_POS_X;
	data->rgb.pos_b = (data->color[data->rgb.set].color % 0x100) *
			(SET_WAY_LGT - SET_BTN_LGT) / 0xFF + SET_WAY_POS_X;
}
