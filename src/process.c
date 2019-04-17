/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:20:52 by jsobel            #+#    #+#             */
/*   Updated: 2019/04/17 18:29:45 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

void	ft_display_ways(t_way *way)
{
	int i;

	if (!way)
		ft_putendl("no way : ERROR");
	while (way)
	{
		i = 0;
		while (way->tab[i])
		{
			printf("- %s_%d ", way->tab[i], way->lenght);
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

int		ft_save_way(t_lemin *data)
{
	data->p = data->list;
	data->i = 0;
	data->weight = data->start->weight;
	data->name = data->start->name;
	if (!(data->l = malloc(sizeof(t_way))))
		exit(EXIT_FAILURE);
	if (!(data->l->tab = malloc(sizeof(char*) * (data->weight))))
		exit(EXIT_FAILURE);
	data->l->tab[data->weight - 1] = 0;
	if (!(data->l->place = ft_intmemalloc(data->weight)))
		exit(EXIT_FAILURE);
	data->l->lenght = data->weight - 1;
	data->l->lants = data->l->lenght;
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
	ft_add_end_list(data);
//	data->l->next = data->way;
//	data->way = data->l;
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

int		ft_process_weight(t_lemin *data)
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
		return (data->start->weight);
	data->weight++;
	if (data->flag)
		return (ft_process_weight(data));
	else
		return (0);
}

void	ft_process(t_lemin *data)
{
	data->weight = 1;
	data->wnbr = 0;
	/*ft_process_weight(data);
	if (data->start->weight && ft_save_way(data) && ++data->wnbr)
		ft_delete_way(data);
	data->lignemax = data->start->weight - 1 + data->ants;
	data->weight = 1;
	ft_reset_weight(data);
	ft_process_weight(data);*/
	while (ft_process_weight(data) && ft_lignemax(data) >= data->start->weight
	&& data->wnbr <= data->ants)
	{
		if (data->start->weight && ft_save_way(data) && ++data->wnbr)
			ft_delete_way(data);
		ft_reset_weight(data);
		data->weight = 1;
		//ft_process_weight(data);
	}
	if (!data->start->weight && !data->way)
		ft_exception("ERROR", data);
	//ft_display_ways(data->way);
	if (!data->start->weight)
		ft_lignemax(data);
}
