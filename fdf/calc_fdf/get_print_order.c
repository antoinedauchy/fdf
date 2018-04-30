/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_print_order.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 19:22:12 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 04:16:29 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		get_first_dir(t_coord layout, t_coord *curr,
				t_coord *next, t_field f)
{
	int		dir;
	int		pos;

	pos = layout.x;
	dir = layout.y;
	if (dir == BOT)
	{
		curr->y = pos / (f.lenght - 1);
		next->y = curr->y + 1;
	}
	else if (dir == TOP)
	{
		curr->y = (f.height - 1) - pos / (f.lenght - 1);
		next->y = curr->y - 1;
	}
	else if (dir == RIGHT)
	{
		curr->x = pos / (f.height - 1);
		next->x = curr->x + 1;
	}
	else if (dir == LEFT)
	{
		curr->x = (f.lenght - 1) - pos / (f.height - 1);
		next->x = curr->x - 1;
	}
}

void		get_second_dir(t_coord layout, t_coord *curr,
				t_coord *next, t_field f)
{
	int		dir;
	int		pos;

	pos = layout.x;
	dir = layout.y;
	if (dir == BOT)
	{
		curr->y = pos % (f.height - 1);
		next->y = curr->y + 1;
	}
	else if (dir == TOP)
	{
		curr->y = (f.height - 1) - pos % (f.height - 1);
		next->y = curr->y - 1;
	}
	else if (dir == RIGHT)
	{
		curr->x = pos % (f.lenght - 1);
		next->x = curr->x + 1;
	}
	else if (dir == LEFT)
	{
		curr->x = (f.lenght - 1) - pos % (f.lenght - 1);
		next->x = curr->x - 1;
	}
}

void		get_print_order(t_data *data, int pos, t_coord *curr, t_coord *next)
{
	t_coord	layout;

	layout.x = pos;
	layout.y = data->dir.x;
	get_first_dir(layout, curr, next, data->field);
	layout.y = data->dir.y;
	get_second_dir(layout, curr, next, data->field);
}
