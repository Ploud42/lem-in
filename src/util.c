/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:24:15 by jsobel            #+#    #+#             */
/*   Updated: 2019/03/05 18:52:26 by jsobel           ###   ########.fr       */
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

void	ft_free_tab(t_lemin *data)
{
	int i;

	i = 0;
	while (data->tab && data->tab[i])
	{
		free(data->tab[i]);
		data->tab[i] = NULL;
		i++;
	}
	free(data->tab);
	data->tab = NULL;
}
