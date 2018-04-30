/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release_hook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:15:27 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 04:19:57 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		mouse_release_hook(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == LEFT_BUTTON)
	{
		data->move.prev_x = 10000;
		data->move.prev_y = 10000;
		data->input.left_button = RELEASED;
		data->action.move = 0;
		data->action.color_block = -1;
		data->action.hill = 0;
		data->action.rot = 0;
		data->action.move_r = 0;
		data->action.move_g = 0;
		data->action.move_b = 0;
	}
	return (0);
}
