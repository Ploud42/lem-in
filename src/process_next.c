/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:11:19 by jsobel            #+#    #+#             */
/*   Updated: 2019/02/21 17:31:17 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include<stdio.h>

int		ft_lignemax(t_lemin *data)
{
	data->i = data->ants;
	data->l = data->way;
	data->lignemax = 1;
	while (data->l)
	{
		if (data->l->lenght > data->lignemax)
			data->lignemax = data->l->lenght;
		data->l = data->l->next;
	}
	data->l = data->way;
	data->flag = 0;
	while (data->i && data->l)
	{
		if (data->l->lants < data->lignemax && data->i-- && data->l->lants++)
			data->flag = 1;
		if (data->l->next)
			data->l = data->l->next;
		else
		{
			if (!data->flag && data->i)
				data->lignemax++;
			data->flag = 0;
			data->l = data->way;
		}
	}
	//printf("lignemax = %d\n", data->lignemax);
	return (data->lignemax);
}

void	ft_delete_way(t_lemin *data)
{
	data->i = 0;
	if (!data->way)
		return ;
	while (data->way && data->way->tab[data->i] && data->way->tab[data->i + 1])
	{
		data->t = data->links;
		while (data->t)
		{
			if (!ft_strcmp(data->way->tab[data->i], data->t->name1) ||
			!ft_strcmp(data->way->tab[data->i], data->t->name2))
			{
				ft_free_link(data);
			}
			else
				data->t = data->t->next;
		}
		data->i++;
	}
}

void	ft_reset_weight(t_lemin *data)
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
