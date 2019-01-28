/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:11:19 by jsobel            #+#    #+#             */
/*   Updated: 2019/01/28 15:17:04 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

void	ft_reset_weight(t_node *list)
{
	t_node *p;

	p = list;
	while (p)
	{
		if (p->value != END)
			p->weight = 0;
		p = p->next;
	}
}