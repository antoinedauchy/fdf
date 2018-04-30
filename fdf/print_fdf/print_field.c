/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:26:37 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 07:41:01 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		print_full_field(t_field field, t_img img, t_data *data)
{
	int			pos;
	t_poly		poly;
	t_coord		tmp;
	t_coord		next;
	t_coord		curr;

	pos = 0;
	get_dir(&data->dir, data);
	while (pos < (field.height - 1) * (field.lenght - 1))
	{
		get_print_order(data, pos, &curr, &next);
		get_point(&poly.a, curr.x, curr.y, data);
		get_point(&poly.b, next.x, curr.y, data);
		get_point(&poly.c, curr.x, next.y, data);
		get_point(&poly.d, next.x, next.y, data);
		print_polygone(poly, img);
		tmp = poly.a;
		poly.a = poly.b;
		poly.b = poly.d;
		poly.d = poly.c;
		poly.c = tmp;
		print_polygone(poly, img);
		pos++;
	}
}

void		print_field(t_field field, t_img img, t_data *data)
{
	int			x;
	int			y;
	t_coord		a;
	t_coord		b;

	y = -1;
	while (++y < field.height)
	{
		x = -1;
		while (++x < field.lenght)
		{
			get_point(&a, x, y, data);
			put_pxl_img(a, img);
			if (x < field.lenght - 1 && get_point(&b, x + 1, y, data))
			{
				data->status == WIRE ? print_line(a, b, img) : 0;
				put_pxl_img(b, img);
			}
			if (y < field.height - 1 && get_point(&b, x, y + 1, data))
			{
				data->status == WIRE ? print_line(a, b, img) : 0;
				put_pxl_img(b, img);
			}
		}
	}
}
