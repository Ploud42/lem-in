/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:10:14 by jsobel            #+#    #+#             */
/*   Updated: 2019/03/14 19:12:32 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include<stdio.h>
// ne pas oublier -g dans makefile
void		ft_display_node(t_node *list, int weight)
{
	while (list)
	{
		ft_putstr(list->name);
		write(1, " ", 1);
		//ft_putnbr(list->x);
		write(1, " ", 1);
		//ft_putnbr(list->y);
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

void	ft_display_links(t_link *links)
{
	t_link *temp;

	temp = links;
	while (temp)
	{
		ft_putstr(temp->name1);
		ft_putstr(" connected with ");
		ft_putstr(temp->name2);
		write(1, "\n", 1);
		temp = temp->next;
	}
}

void	ft_exception(char *s, t_lemin *data)
{
	ft_putendl(s);
	ft_free_lemin(data);
	exit(EXIT_FAILURE);
}

int		main(void)
{
	t_lemin	data;

	data.list = NULL;
	data.links = NULL;
	data.way = NULL;
	data.start = NULL;
	data.end = NULL;
	data.name = NULL;
	data.value = 0;
	data.ants = 0;
	data.i = 0;
	data.tab = NULL;
	while (get_next_line(0, &data.line) > 0 && ft_check_line(&data))
	{
		ft_putendl(data.line);
		free(data.line);
		data.line = NULL;
	}
	if (!data.start || !data.end)
		ft_exception("ERROR", &data);
	//ft_display_node(data.list, 0);
	//ft_display_links(data.links);
	ft_process(&data);
	//ft_display_node(data.list, 1);
	//printf("%d fourmis\n", data.ants);
	if (data.way)
		ft_display_lines(&data);
	ft_free_lemin(&data);
	return (0);
}
