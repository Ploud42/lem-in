/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:08:31 by jsobel            #+#    #+#             */
/*   Updated: 2019/03/14 19:35:17 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include<stdio.h>

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

static int	ft_check_link(t_lemin *data)
{
	data->t = data->links;
	while (data->t)
	{
		if (!ft_strcmp(data->t->name1, data->tab[0]) &&
		!ft_strcmp(data->t->name2, data->tab[1]))
			return (0);
		else if (!ft_strcmp(data->t->name1, data->tab[1]) &&
		!ft_strcmp(data->t->name2, data->tab[0]))
			return (0);
		data->t = data->t->next;
	}
	return (1);
}

static int	ft_creat_links(t_lemin *data)
{
	if (!(data->tab = ft_strsplit(data->line, '-')))
		exit(EXIT_FAILURE);
	if (ft_tablen(data->tab) == 2 && ft_check_name(data, data->tab[0]) &&
	ft_check_name(data, data->tab[1])
	&& ft_strcmp(data->tab[0], data->tab[1]) && ft_check_link(data))
	{
		if (!(data->t = malloc(sizeof(t_link))))
			exit(EXIT_FAILURE);
		data->t->next = data->links;
		data->links = data->t;
		if (!(data->t->name1 = ft_strdup(data->tab[0])))
			exit(EXIT_FAILURE);
		if (!(data->t->name2 = ft_strdup(data->tab[1])))
			exit(EXIT_FAILURE);
		ft_free_tab(data);
		data->tab = NULL;
		return (1);
	}
	else
	{
		ft_free_tab(data);
		return (0);
	}
}

static void	ft_creat_node(t_lemin *data)
{
	data->tab = ft_strsplit(data->line, ' ');
	if (!ft_check_name(data, data->tab[0]) && ft_tablen(data->tab) == 3 &&
	ft_strisdigit(data->tab[1]) && ft_strisdigit(data->tab[2]))
	{
		if (!(data->p = malloc(sizeof(t_node))))
			exit(EXIT_FAILURE);
		data->p->next = data->list;
		data->list = data->p;
		if (!(data->p->name = ft_strdup(data->tab[0])))
			exit(EXIT_FAILURE);
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
		ft_exception("ERROR", data);
	ft_free_tab(data);
}

int			ft_check_line(t_lemin *data)
{
	if (!data->ants && data->line[0] != '#' && data->line[0] != 'L')
	{
		if (!ft_strisdigit(data->line) || !(data->ants = ft_atoui(data->line))
		|| data->ants > 2147483647)
			ft_exception("ERROR", data);
	}
	else if (data->line[0] != '#' && data->line[0] != 'L' &&
	ft_space_count(data->line))
		ft_creat_node(data);
	else if (data->line[0] == '#' && data->line[1] == '#')
	{
		if (!ft_strcmp(&data->line[2], "start"))
			data->value = START;
		else if (!ft_strcmp(&data->line[2], "end"))
			data->value = END;
		else
			ft_exception("ERROR", data);
	}
	else if (data->line[0] != '#' && data->line[0] != 'L' &&
	ft_strchr(data->line, '-') == ft_strrchr(data->line, '-'))
		return (ft_creat_links(data));
	else if (!(data->line[0] == '#'))
		return (0);
	return (1);
}
