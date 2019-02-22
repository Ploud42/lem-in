/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:24:15 by jsobel            #+#    #+#             */
/*   Updated: 2019/02/22 18:53:37 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include<stdio.h>

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

void	ft_free_link(t_lemin *data)
{
	t_link *temp;

	temp = data->links;
	if (data->t == data->links)
		data->links = data->links->next;
	else
	{
		while (temp->next && temp->next != data->t)
			temp = temp->next;
		temp->next = data->t->next;
	}
	free(data->t->name1);
	free(data->t->name2);
	free(data->t);
	if (temp)
		data->t = temp->next;
	else
		data->t = data->links;
}

void	ft_free_tab(t_lemin *data)
{
	int i;

	i = 0;
	while (data->tab[i])
	{
		free(data->tab[i]);
		i++;
	}
	free(data->tab);
	data->tab = NULL;
}
