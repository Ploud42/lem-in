/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:20:52 by jsobel            #+#    #+#             */
/*   Updated: 2019/01/23 18:01:39 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

void	ft_display_ways(t_way *way)
{
	int i;

	i = 0;
	if (!way)
		ft_putendl("no way : ERROR");
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

void	ft_delete_way(t_lemin *data)
{
	data->i = 0;
	if (!data->way)
		return ;
	while (data->way && data->way->tab[data->i] && data->way->tab[data->i + 1])
	{
		data->t = data->links;
		printf("ok\n");
		while (data->t)
		{
			if (!ft_strcmp(data->way->tab[data->i], data->t->name1) ||
			!ft_strcmp(data->way->tab[data->i++], data->t->name2))
			{
				data->t = data->t->next;
				//ft_free_link(data);
			}
			else
				data->t = data->t->next;
		}
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

int		ft_save_way(t_lemin *data)
{
	data->p = data->list;
	data->i = 0;
	if (!data->start->weight)
		return (0);
	data->weight = data->start->weight;
	data->name = data->start->name;
	if (!(data->l = ft_memalloc(sizeof(t_way))))
		exit(EXIT_FAILURE);
	if (!(data->l->tab = ft_memalloc(sizeof(char*) * (data->weight - 1))))
		exit(EXIT_FAILURE);
	while (data->weight-- > 1)
	{
		data->p = data->list;
		while (data->p && !((data->p->weight == data->weight)
		&& ft_connect(data, data->p->name)))
			data->p = data->p->next;
		if (data->p && !(data->l->tab[data->i++] = ft_strdup(data->p->name)))
			exit(EXIT_FAILURE);
		data->name = data->p->name;
	}
	data->l->next = data->way;
	data->way = data->l;
	return (1);
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
	if (data->start->weight)
		return ;
	data->weight++;
	if (data->flag)
		ft_process_weight(data);
}

void	ft_process(t_lemin *data)
{
	data->weight = 1;
	ft_process_weight(data);
	printf("weight processed\n");
	ft_save_way(data);
	printf("way saved\n");
	ft_delete_way(data);
	printf("way deleted\n");
	ft_display_ways(data->way);
}
