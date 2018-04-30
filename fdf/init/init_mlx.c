/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:09:17 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 23:42:06 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			init_img(t_img *img, void *mlx, int lenght, int height)
{
	if ((img->img = mlx_new_image(mlx, lenght, height)) == NULL)
		return (-1);
	if ((img->data = mlx_get_data_addr(img->img, &img->bpb,
		&img->sizeline, &img->endian)) == NULL)
		return (-1);
	img->lenght = lenght;
	img->height = height;
	return (0);
}

int			init_color(t_block **color)
{
	if ((*color = (t_block*)malloc(3 * sizeof(t_block))) == NULL)
		return (-1);
	(*color)[0].percent = 0;
	(*color)[0].color = 0x00FF00;
	(*color)[0].status = 1;
	(*color)[0].pos = COLORS_POS_Y + COLORS_HEIGHT - BLOCK_HEIGHT;
	(*color)[1].percent = 50;
	(*color)[1].color = 0x433100;
	(*color)[1].status = 1;
	(*color)[1].pos = 50 * (COLORS_HEIGHT - BLOCK_HEIGHT) / 100 + COLORS_POS_Y;
	(*color)[2].percent = 100;
	(*color)[2].color = 0xFFFFFF;
	(*color)[2].status = 1;
	(*color)[2].pos = COLORS_POS_Y;
	return (0);
}

int			init_mlx(t_data *data)
{
	if ((data->mlx = mlx_init()) == NULL)
		return (-1);
	if ((data->win = mlx_new_window(data->mlx, LENGHT_WIN,
					HEIGHT_WIN, "FDF")) == NULL)
		return (-1);
	init_data(data);
	if (init_img(&data->img, data->mlx, LENGHT_WIN, HEIGHT_WIN) == -1)
		return (-1);
	if (init_color(&data->color) == -1)
		return (-1);
	init_ext_height(&data->min_height, &data->max_height, data->field);
	set_rgb(data);
	return (0);
}
