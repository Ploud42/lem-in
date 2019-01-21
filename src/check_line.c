/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:08:31 by jsobel            #+#    #+#             */
/*   Updated: 2019/01/21 17:18:08 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include<stdio.h>

void		ft_display_node(t_node *list, int weight)
{
	while (list)
	{
		ft_putstr(list->name);
		write(1, " ", 1);
		ft_putnbr(list->x);
		write(1, " ", 1);
		ft_putnbr(list->y);
		if (list->value == START)
			ft_putstr(" start\n");
		else if (list->value == END)
			ft_putstr(" end\n");
		else
			ft_putstr(" room\n");
		if (weight)
		{
			printf("weight = %d\n", list->weight);
		}
		list = list->next;
	}
}

int			ft_check_name(t_lemin *data, char *name)
{
	t_node	*p;
	int		i;

	p = data->list;
	i = 1;
	while (p)
	{
		if (p->value == START)
			data->start = ft_strdup(p->name);
		else if (p->value == END)
		{
			data->end = ft_strdup(p->name);
			p->weight = 1;
		}
		if (!ft_strcmp(p->name, name))
			return (i);
		p = p->next;
		i++;
	}
	return (0);
}

static void ft_creat_links(t_lemin *data)
{
	t_link	*new;

	data->i = -1;
	data->tab = ft_strsplit(data->line, '-');
	if (ft_check_name(data, data->tab[0]) && ft_check_name(data, data->tab[1]))
	{
		if (!(new = ft_memalloc(sizeof(t_link))))
			ft_exception("ERROR");
		new->next = data->links;
		data->links = new;
		if (!(new->name1 = ft_strdup(data->tab[0])))
			ft_exception("ERROR");
		if (!(new->name2 = ft_strdup(data->tab[1])))
			ft_exception("ERROR");
	}
	else
		ft_exception("ERROR");
	while (data->tab[++data->i])
		free(data->tab[data->i]);
	free(data->tab);
}

static void	ft_creat_node(t_lemin *data)
{
	t_node	*new;

	data->i = -1;
	data->tab = ft_strsplit(data->line, ' ');
	data->name = data->tab[0];
	if (!ft_check_name(data, data->name))
	{
		if (!(new = ft_memalloc(sizeof(t_node))))
			ft_exception("ERROR");
		new->next = data->list;
		data->list = new;
		if (!(new->name = ft_strdup(data->name)))
			ft_exception("ERROR");
		new->x = ft_atoi(data->tab[1]);
		new->y = ft_atoi(data->tab[2]);
		new->weight = 0;
		new->value = data->value;
		data->value = 0;
	}
	else
		ft_exception("ERROR");
	while (data->tab[++data->i])
		free(data->tab[data->i]);
	free(data->tab);
}

int			ft_check_line(t_lemin *data)
{
	if (!data->ants && data->line[0] != '#' && data->line[0] != 'L')
	{
		while (data->line[data->i])
		{
			if (!ft_isdigit(data->line[data->i++]))
				ft_exception("ERROR");
		}
		if (!(data->ants = ft_atoi(data->line)))
			ft_exception("ERROR");
	}
	else if (data->line[0] != '#' && data->line[0] != 'L' &&
	ft_strchr(data->line, ' '))
		ft_creat_node(data);
	else if (data->line[0] == '#' && data->line[1] == '#')
	{
		if (!ft_strcmp(&data->line[2], "start"))
			data->value = START;
		else if (!ft_strcmp(&data->line[2], "end"))
			data->value = END;
	}
	else if (data->line[0] != '#' && data->line[0] != 'L' &&
	ft_strchr(data->line, '-'))
		ft_creat_links(data);
	else if (!(data->line[0] == '#'))
		return (0);
	return (1);
}