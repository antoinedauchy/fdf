/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 18:58:34 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 04:16:50 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		move_field(t_data *data)
{
	if (data->action.move)
	{
		if (data->move.right && (data->pos.y_angle - data->move.right) >= -90)
			data->pos.y_angle -= data->move.right;
		else if (data->move.left && (data->pos.y_angle + data->move.left) <= 90)
			data->pos.y_angle += data->move.left;
		if (data->move.top && (data->pos.x_angle + data->move.top) <= 90)
			data->pos.x_angle += data->move.top;
		else if (data->move.bot && (data->pos.x_angle - data->move.bot) >= -90)
			data->pos.x_angle -= data->move.bot;
	}
}
