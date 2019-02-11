/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:08:31 by jsobel            #+#    #+#             */
/*   Updated: 2019/02/08 17:19:36 by juliensobel      ###   ########.fr       */
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
		if (!ft_strcmp(p->name, name))
			return (i);
		p = p->next;
		i++;
	}
	return (0);
}

static void ft_creat_links(t_lemin *data)
{
	data->tab = ft_strsplit(data->line, '-');
	if (ft_check_name(data, data->tab[0]) && ft_check_name(data, data->tab[1]))
	{
		if (!(data->t = malloc(sizeof(t_link))))
			ft_exception("ERROR");
		data->t->next = data->links;
		data->links = data->t;
		if (!(data->t->name1 = ft_strdup(data->tab[0])))
			ft_exception("ERROR");
		if (!(data->t->name2 = ft_strdup(data->tab[1])))
			ft_exception("ERROR");
	}
	else
		ft_exception("ERROR");
	//ft_free_tab(data);
}

static void	ft_creat_node(t_lemin *data)
{
	data->tab = ft_strsplit(data->line, ' ');
	if (!ft_check_name(data, data->tab[0]))
	{
		if (!(data->p = malloc(sizeof(t_node))))
			ft_exception("ERROR");
		data->p->next = data->list;
		data->list = data->p;
		if (!(data->p->name = ft_strdup(data->tab[0])))
			ft_exception("ERROR");
		data->p->x = ft_atoi(data->tab[1]);
		data->p->y = ft_atoi(data->tab[2]);
		data->p->weight = 0;
		data->p->value = data->value;
		data->value = 0;
		if (data->p->value == START)
			data->start = data->p;
		else if (data->p->value == END)
		{
			data->end = data->p;
			data->p->weight = 1;
		}
	}
	else
		ft_exception("ERROR");
	//ft_free_tab(data);
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
