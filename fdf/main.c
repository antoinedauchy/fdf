/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:03:47 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 08:16:51 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (put_err("Usage : ./fdf [file]"));
	if (get_map(av[1], &data.field) == -1)
		return (-1);
	if (init_mlx(&data) == -1)
		return (-1);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, MTN_NTFY, MTN_NTFY_MSK, mouse_hook, &data);
	mlx_hook(data.win, BTNPRESS, BTNPRESSMSK, mouse_press_hook, &data);
	mlx_hook(data.win, BTNRELEASE, BTNRELEASEMSK, mouse_release_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
