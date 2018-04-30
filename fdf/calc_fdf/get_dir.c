/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:15:40 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 04:16:25 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		get_dir(t_coord *dir, t_data *data)
{
	if (data->pos.x_angle >= 0)
		dir->x = BOT;
	else
		dir->x = TOP;
	if (data->pos.y_angle >= 0)
		dir->y = RIGHT;
	else
		dir->y = LEFT;
	if (ft_abs(data->pos.x_angle) < ft_abs(data->pos.y_angle))
		ft_swap(&dir->x, &dir->y);
}
