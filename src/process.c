/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:20:52 by jsobel            #+#    #+#             */
/*   Updated: 2019/01/22 19:15:58 by juliensobel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

void	ft_display_ways(t_way *way)
{
	int i;

	i = 0;
	while (way)
	{
		while (way->tab[i])
		{
			printf("%s ", way->tab[i]);
			i++;
		}
		printf("is a way\n");
		way = way->next;
	}
}

int		ft_connect(t_lemin *data, char *name)
{
	data->t = data->links;
	while (data->t)
	{
		if (!ft_strcmp(data->name, data->t->name1) &&
		!ft_strcmp(name, data->t->name2))
			return (1);
		else if (!ft_strcmp(data->name, data->t->name2) &&
		!ft_strcmp(name, data->t->name1))
			return (1);
		data->t = data->t->next;
	}
	return (0);
}

void	ft_save_way(t_lemin *data)
{
	data->p = data->list;
	data->i = 0;
	while (data->p && data->p->value != START)
		data->p = data->p->next;
	data->weight = data->p->weight;
	data->name = data->p->name;
	if (!(data->way = ft_memalloc(sizeof(t_way))))
		exit(EXIT_FAILURE);
	if (!(data->way->tab = ft_memalloc(sizeof(char*) * (data->weight - 1))))
		exit(EXIT_FAILURE);
	while (data->weight-- > 1)
	{
		data->p = data->list;
		while (data->p && !((data->p->weight == data->weight)
		&& ft_connect(data, data->p->name)))
			data->p = data->p->next;
		if (data->p && !(data->way->tab[data->i++] = ft_strdup(data->p->name)))
			exit(EXIT_FAILURE);
		data->name = data->p->name;
	}
	data->way->next = NULL;
}

void	ft_put_weight(t_lemin *data, char *name, int weight)
{
	t_node *l;

	l = data->list;
	while (l)
	{
		if (!ft_strcmp(l->name, name) &&
		(!l->weight || l->weight > (weight + 1)))
		{
			l->weight = weight + 1;
			if (l->value == START)
				data->flag = START;
			else
				data->flag = 1;
			return ;
		}
		l = l->next;
	}
}

void	ft_process_weight(t_lemin *data)
{
	data->p = data->list;
	data->flag = 0;
	while (data->p)
	{
		data->t = data->links;
		if (data->p->weight == data->weight)
		{
			while (data->t)
			{
				if (!ft_strcmp(data->t->name1, data->p->name))
					ft_put_weight(data, data->t->name2, data->weight);
				else if (!ft_strcmp(data->t->name2, data->p->name))
					ft_put_weight(data, data->t->name1, data->weight);
				data->t = data->t->next;
			}
		}
		data->p = data->p->next;
	}
	if (data->flag == START)
		return ;
	data->weight++;
	if (data->flag)
		ft_process_weight(data);
}

void	ft_process(t_lemin *data)
{
	data->weight = 1;
	ft_process_weight(data);
	data->l = data->way;
	ft_save_way(data);
	ft_display_ways(data->way);
}
