/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:11:19 by jsobel            #+#    #+#             */
/*   Updated: 2019/04/17 18:07:40 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include<stdio.h>

static void	ft_fill_the_cup(t_lemin *data)
{
	int ants;

	ants = data->ants;
	while (ants && data->l)
	{
		if (data->l->lants <= data->lignemax)
		{
			ants--;
			data->l->lants++;
			data->flag = 1;
		}
		if (data->l->next)
			data->l = data->l->next;
		else
		{
			if (!data->flag && ants)
				data->lignemax++;
			data->flag = 0;
			data->l = data->way;
		}
	}
}

int			ft_lignemax(t_lemin *data)
{
	data->l = data->way;
	data->lignemax = 1;
	if (!data->way)
	 return (data->start->weight);
	while (data->l)
	{
		if (data->l->lenght > data->lignemax)
			data->lignemax = data->l->lenght;
		data->l = data->l->next;
	}
	data->l = data->way;
	data->flag = 0;
	//printf("lignemax before the cup is filled = %d\n", data->lignemax);
	ft_fill_the_cup(data);
	return (data->lignemax);
}

void		ft_delete_way(t_lemin *data)
{
	data->i = 0;
	if (!data->way)
		return ;
	while (data->l && data->l->tab[data->i] && data->l->tab[data->i + 1])
	{
		data->t = data->links;
		while (data->t)
		{
			if (!ft_strcmp(data->l->tab[data->i], data->t->name1) ||
			!ft_strcmp(data->l->tab[data->i], data->t->name2))
			{
				ft_free_link(data);
			}
			else
				data->t = data->t->next;
		}
		data->i++;
	}
}

void		ft_add_end_list(t_lemin *data)
{
	t_way *temp;

	temp = data->way;
	while (temp && temp->next)
		temp = temp->next;
	if (temp)
		temp->next = data->l;
	else
		data->way = data->l;
	data->l->next = NULL;
}

void		ft_reset_weight(t_lemin *data)
{
	t_node *p;

	p = data->list;
	while (p)
	{
		if (p->value != END)
			p->weight = 0;
		p = p->next;
	}
	data->l = data->way;
	while (data->l)
	{
		data->l->lants = data->l->lenght;
		data->l = data->l->next;
	}
}
