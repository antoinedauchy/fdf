/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 23:06:19 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 04:19:18 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int				loop_hook(t_data *data)
{
	move_field(data);
	print_in_frame(data);
	if (data->status == WIRE || data->status == POINT)
		print_field(data->field, data->img, data);
	else
		print_full_field(data->field, data->img, data);
	print_ex_frame(data);
	print_panel(data);
	reset_moves(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
