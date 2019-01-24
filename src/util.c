/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:24:15 by jsobel            #+#    #+#             */
/*   Updated: 2019/01/24 18:49:31 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include<stdio.h>

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
	printf("ok\n");
	free(data->t->name1);
	free(data->t->name2);
	free(data->t);
	if (temp)
		data->t = temp->next;
	else
		data->t = data->links;
}

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}