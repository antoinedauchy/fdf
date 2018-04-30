/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ext_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:01:57 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 04:17:48 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		get_prop_height(int *max, int *min, t_field field)
{
	int		y;
	int		x;
	int		diff;

	diff = *max - *min;
	y = 0;
	while (y < field.height)
	{
		x = 0;
		while (x < field.lenght)
		{
			field.map[y][x].height =
				field.map[y][x].height * 200 / diff;
			x++;
		}
		y++;
	}
	*max = *max * 200 / diff;
	*min = *min * 200 / diff;
}

void		init_ext_height(int *min, int *max, t_field field)
{
	int		x;
	int		y;
	int		n;

	y = 0;
	*min = field.map[0][0].height;
	*max = field.map[0][0].height;
	while (y < field.height)
	{
		x = 0;
		while (x < field.lenght)
		{
			n = field.map[y][x].height;
			if (n > *max)
				*max = n;
			if (n < *min)
				*min = n;
			x++;
		}
		y++;
	}
	if (*max - *min > 200)
		get_prop_height(max, min, field);
}
