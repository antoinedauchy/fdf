/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 02:59:51 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 07:46:44 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		get_x_rotation(t_coord *point, int x, int y, t_data *data)
{
	double	rad;
	double	y_rot;
	double	z_rot;
	double	l_y;
	double	l_z;

	l_y = point->y;
	l_z = data->field.map[y][x].z;
	y_rot = ((double)data->field.height - 1.0) * data->pos.zoom / 2.0;
	z_rot = 0;
	rad = data->pos.x_angle * 3.1415 / 180.0;
	point->y = (l_y - y_rot) * cos(rad) - (l_z - z_rot) * sin(rad) + y_rot;
	data->field.map[y][x].z = (l_y - y_rot) * sin(rad) +
		(l_z - z_rot) * cos(rad) + z_rot;
}

void		get_y_rotation(t_coord *point, int x, int y, t_data *data)
{
	double	rad;
	double	x_rot;
	double	z_rot;
	double	l_x;
	double	l_z;

	l_x = point->x;
	l_z = data->field.map[y][x].z;
	x_rot = ((double)data->field.lenght - 1.0) * data->pos.zoom / 2.0;
	z_rot = 0;
	rad = data->pos.y_angle * 3.1415 / 180.0;
	point->x = (l_x - x_rot) * cos(rad) - (l_z - z_rot) * sin(rad) + x_rot;
	data->field.map[y][x].z = (l_x - x_rot) * sin(rad) +
		(l_z - z_rot) * cos(rad) + z_rot;
}

void		get_z_rotation(t_coord *point, t_data *data)
{
	double	rad;
	double	x_rot;
	double	y_rot;
	double	x;
	double	y;

	x = point->x;
	y = point->y;
	x_rot = ((double)data->field.lenght - 1.0) * data->pos.zoom / 2.0;
	y_rot = ((double)data->field.height - 1.0) * data->pos.zoom / 2.0;
	rad = data->pos.z_angle * 3.1415 / 180.0;
	point->x = (x - x_rot) * cos(rad) - (y - y_rot) * sin(rad) + x_rot;
	point->y = (x - x_rot) * sin(rad) + (y - y_rot) * cos(rad) + y_rot;
}

int			get_point(t_coord *point, int x, int y, t_data *data)
{
	point->x = x * data->pos.zoom;
	point->y = y * data->pos.zoom;
	data->field.map[y][x].z = data->field.map[y][x].height * data->pos.zoom *
		(double)((double)data->hill.percent / 100.0);
	get_x_rotation(point, x, y, data);
	get_y_rotation(point, x, y, data);
	get_z_rotation(point, data);
	point->x += POS_X_MAP;
	point->x -= ((double)data->field.lenght - 1.0) *
		(double)data->pos.zoom / 2.0;
	point->y += POS_Y_MAP;
	point->y -= ((double)data->field.height - 1.0) *
		(double)data->pos.zoom / 2.0;
	if (data->color_param == SET_COLOR)
	{
		point->color = get_set_color(data->color, data->field.map[y][x].height,
			data->min_height, data->max_height);
	}
	else if (data->color_param == SOURCE_COLOR)
		point->color = data->field.map[y][x].color;
	return (1);
}
