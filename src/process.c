/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:20:52 by jsobel            #+#    #+#             */
/*   Updated: 2019/01/15 19:38:16 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_put_weight(t_lemin *data, char *name, int weight)
{
	t_link *l;

	l = data->list;
	while (l)
	{
		if (l->name = name && (!l->weight || l->weight > weight))
		{
			l->weight = weight;
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
				if (data->t->name1 == data->p->name)
					ft_put_weight(data, data->t->name2, data->p->weight);
				else if (data->t->name2 == data->p->name)
					ft_put_weight(data, data->t->name1, data->p->weight);
				data->t = data->t->next;
			}
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