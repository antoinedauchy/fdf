/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_in_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 02:13:12 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 04:21:58 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			cursor_in_square(t_coord pos, t_coord size, int x, int y)
{
	if (x >= pos.x && x < pos.x + size.x &&
		y >= pos.y && y < pos.y + size.y)
		return (1);
	return (0);
}
