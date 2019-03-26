/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:09:36 by jsobel            #+#    #+#             */
/*   Updated: 2019/03/26 19:14:50 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_free_next(t_lemin *data)
{
	while (data->way)
	{
		data->i = 0;
		while (data->way->tab[data->i])
			free(data->way->tab[data->i++]);
		free(data->way->tab);
		free(data->way->place);
		data->l = data->way;
		data->way = data->way->next;
		free(data->l);
	}
	if (data->line)
		free(data->line);
	ft_free_tab(data);
}

void	ft_free_lemin(t_lemin *data)
{
	while (data->list)
	{
		free(data->list->name);
		data->list->name = NULL;
		data->p = data->list;
		data->list = data->list->next;
		free(data->p);
	}
	while (data->links)
	{
		free(data->links->name1);
		free(data->links->name2);
		data->t = data->links;
		data->links = data->links->next;
		free(data->t);
	}
	ft_free_next(data);
}

void	ft_free_link(t_lemin *data)
{
	t_link *temp;

	temp = data->links;
	if (data->t == data->links)
	{
			data->links = data->links->next;
			data->t = data->links;
			free(temp->name1);
			free(temp->name2);
			free(temp);
	}
	else
	{
		while (temp->next && temp->next != data->t)
			temp = temp->next;
		temp->next = data->t->next;
		free(data->t->name1);
		free(data->t->name2);
		free(data->t);
		data->t = temp->next;
	}
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