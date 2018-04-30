/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:01:46 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 07:20:42 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		get_set_color(t_block *color, int height, int min, int max)
{
	int	percent;
	int	n_start;
	int	n_end;

	if (min < 0)
	{
		height -= min;
		max -= min;
		min = 0;
	}
	if (max - min == 0)
		return (color[1].color);
	percent = 100 * height / (max - min);
	n_start = 0;
	while (n_start < 2 && percent > color[n_start + 1].percent)
		n_start++;
	n_end = n_start + 1;
	if (n_start == 2 || (!n_start && percent < color[0].percent))
		return (0x0);
	return (get_color(percent - color[n_start].percent,
		color[n_end].color, color[n_start].color,
		color[n_end].percent - color[n_start].percent));
}
