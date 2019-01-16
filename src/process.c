/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:20:52 by jsobel            #+#    #+#             */
/*   Updated: 2019/01/16 19:52:45 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

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
		if (data->p->weight)
		{
			while (data->t)
			{
				if (!ft_strcmp(data->t->name1, data->p->name))
					ft_put_weight(data, data->t->name2, data->p->weight);
				else if (!ft_strcmp(data->t->name2, data->p->name))
					ft_put_weight(data, data->t->name1, data->p->weight);
				data->t = data->t->next;
			}
			if (data->flag == START)
				return ;
		}
		data->p = data->p->next;
	}
	if (data->flag)
		ft_process_weight(data);
}

void	ft_process(t_lemin *data)
{
	ft_process_weight(data);
}