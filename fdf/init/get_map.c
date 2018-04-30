/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 21:03:01 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 04:18:27 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "../fdf.h"
#include "../tools/get_next_line.h"

int			get_height_map(char *name, t_field *field)
{
	int		fd;
	int		ret;
	char	*line;

	if ((fd = open(name, O_RDONLY)) == -1)
		return (put_err("open failed"));
	field->height = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
		field->height += 1;
	if (ret == -1)
		return (put_err("get_next_line failed"));
	close(fd);
	return (0);
}

void		write_point(t_point *line, char *file, int *i, int *n)
{
	line[*i].height = get_nbr(&file[*n], "0123456789");
	while (file[*n] && file[*n] != ' ' && file[*n] != ','
			&& file[*n] != '\n')
		*n += 1;
	line[*i].color = 0xFFFFFF;
	if (file[*n] == ',')
		line[*i].color = get_nbr(&file[*n + 3], "0123456789ABCDEF");
	while (file[*n] && file[*n] != ' ' && file[*n] != '\n')
		*n += 1;
	while (file[*n] == ' ')
		*n += 1;
}

int			write_map(char **file, t_field *field)
{
	int		count;
	int		i;
	int		n;

	count = 0;
	if ((field->map = (t_point**)malloc(field->height *
					sizeof(t_point*))) == NULL)
		return (put_err("malloc failed"));
	while (count < field->height)
	{
		i = 0;
		n = 0;
		if ((field->map[count] = (t_point*)malloc(field->lenght *
						sizeof(t_point))) == NULL)
			return (put_err("malloc failed"));
		while (file[count][n] == ' ')
			n++;
		while (file[count][n] && file[count][n] != '\n')
		{
			write_point(field->map[count], file[count], &i, &n);
			i += 1;
		}
		count++;
	}
	return (0);
}

int			get_map(char *name, t_field *field)
{
	int		count;
	int		fd;
	int		ret;
	char	**file;

	count = 0;
	if (get_height_map(name, field) == -1)
		return (-1);
	if ((file = (char**)malloc((field->height + 1) * sizeof(char*))) == NULL)
		return (put_err("malloc failed"));
	if ((fd = open(name, O_RDONLY)) == -1)
		return (put_err("open failed"));
	while ((ret = get_next_line(fd, &file[count])) == 1)
		count++;
	close(fd);
	if (ret == -1)
		return (put_err("get_next_line failed"));
	if (check_file(file, field->height, &field->lenght) == -1)
		return (-1);
	if (write_map(file, field) == -1)
		return (-1);
	return (0);
}
