/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:09:36 by jsobel            #+#    #+#             */
/*   Updated: 2019/02/21 18:51:43 by jsobel           ###   ########.fr       */
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
}

void	ft_free_lemin(t_lemin *data)
{
	while (data->list)
	{
		free(data->list->name);
		data->p = data->list;
		data->list = data->list->next;
		free(data->p);
	}
	while (data->links)
	{
		data->i = 0;
		while (data->links->tab[data->i])
			free(data->links->tab[data->i++]);
		free(data->links->tab);
		data->t = data->links;
		data->links = data->links->next;
		free(data->t);
	}
	ft_free_next(data);
}