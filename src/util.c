/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:24:15 by jsobel            #+#    #+#             */
/*   Updated: 2019/03/06 17:54:47 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include<stdio.h>

int		*ft_intmemalloc(size_t size)
{
	int		*temp;
	size_t	i;

	i = 0;
	if (!(temp = malloc(sizeof(int) * size)))
		return (NULL);
	while (i < size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}

int		ft_space_count(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count == 2);
}

int		ft_tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		ft_strisdigit(char *str)
{
	int i;
	int c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (!(c >= 48 && c <= 57))
			return (0);
		i++;
	}
	return (1);
}

uint	ft_atoui(const char *str)
{
	size_t	i;
	uint	nb;
	uint	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\f' || *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		nb += str[i] - 48;
		if (str[i + 1] && '0' <= str[i + 1] && str[i + 1] <= '9')
			nb *= 10;
		i++;
	}
	return (nb * sign);
}
