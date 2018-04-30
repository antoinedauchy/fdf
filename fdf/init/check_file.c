/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 22:57:52 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 04:17:31 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			check_color(char *file, int *n)
{
	int		count;

	count = 0;
	file += 1;
	if (*(file++) != '0')
		return (put_err("error in prefix color"));
	if (*(file++) != 'x')
		return (put_err("error in prefix color"));
	while (file[count] && file[count] != ' ' && file[count] != '\n')
	{
		if (get_value(file[count], "0123456789ABCDEF") == -1)
			return (put_err("error in syntax color"));
		count++;
	}
	if (count == 0 || count > 6)
		return (put_err("error in size color"));
	while (file[count] == ' ')
		count += 1;
	if (file[count] && file[count] != '\n' &&
		!(file[count] >= '0' && file[count] <= '9'))
		return (put_err("error in end color"));
	*n += count + 3;
	return (0);
}

int			check_point(char *file, int *n)
{
	int		count;

	count = 0;
	if (file[count] == '-')
		count++;
	while (file[count] >= '0' && file[count] <= '9')
		count += 1;
	if ((file[0] == '-' && count == 1) || count == 0)
		return (put_err("error in point"));
	while (file[count] == ' ')
		count++;
	if (file[count] && file[count] != ',' && file[count] != '\n' &&
			!(file[count] >= '0' && file[count] <= '9') && file[count] != '-')
		return (put_err("error in end point"));
	if (file[count] == ',' && check_color(&file[count], &count) == -1)
		return (-1);
	*n += count;
	return (0);
}

int			check_file(char **file, int height, int *lenght)
{
	int		count;
	int		tmp;
	int		n;

	count = 0;
	*lenght = 0;
	while (count < height)
	{
		n = 0;
		tmp = 0;
		while (file[count][n] == ' ')
			n++;
		while (file[count][n] && file[count][n] != '\n')
		{
			if (check_point(&file[count][n], &n) == -1)
				return (-1);
			tmp += 1;
		}
		if (*lenght == 0)
			*lenght = tmp;
		if (tmp != *lenght || tmp == 0)
			return (put_err("error in lenght file"));
		count++;
	}
	return (0);
}
