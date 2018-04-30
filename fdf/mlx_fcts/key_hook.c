/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 23:09:33 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 07:44:59 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		key_hook(int keycode, t_data *data)
{
	if (keycode == ECHAP)
	{
		if (data->color_param == SET_COLOR)
			data->color_param = SOURCE_COLOR;
		else
			exit(0);
	}
	return (0);
}
