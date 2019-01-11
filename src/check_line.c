/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:08:31 by jsobel            #+#    #+#             */
/*   Updated: 2019/01/11 18:08:12 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			ft_check_name(t_lemin *data)
{
	t_node	*p;
	int		i;

	p = data->list;
	i = 1;
	while (p)
	{
		if (ft_strcmp(p->name, data->name))
			return (i);
		p = p->next;
		i++;
	}
	return (0);
}

static void	ft_creat_node(t_lemin *data)
{
	data->tab = ft_strsplit(data->line, ' ');
	data->name = data->tab[0];
	if (!ft_check_name(data))
	{
		(void) data->i;
	}
}

void		ft_check_line(t_lemin *data)
{
	if (data->line[0] != '#' && ft_strchr(data->line, ' '))
	{
		ft_creat_node(data);
	}
}