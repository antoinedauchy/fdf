/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 21:59:36 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 04:22:20 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			get_value(char c, char *base)
{
	int		n;

	n = 0;
	while (base[n])
	{
		if (c == base[n] ||
			(c >= 'a' && c <= 'f' && base[n] == c - 32) ||
			(c >= 'A' && c <= 'F' && base[n] == c + 32))
			return (n);
		n++;
	}
	return (-1);
}

int			get_nbr(char *str, char *base)
{
	int		n;
	int		nb;
	int		len_base;
	int		minus;

	nb = 0;
	n = 0;
	len_base = ft_strlen(base);
	minus = 0;
	if (str[0] == '-' && (n += 1))
		minus = 1;
	while (get_value(str[n], base) != -1)
	{
		nb = nb * len_base + get_value(str[n], base);
		n++;
	}
	if (minus)
		return (-nb);
	return (nb);
}
