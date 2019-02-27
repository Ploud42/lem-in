/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:10:14 by jsobel            #+#    #+#             */
/*   Updated: 2019/02/27 19:12:03 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include<stdio.h>

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

void	ft_exception(char *s)
{
	ft_putendl(s);
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
		ft_exception("ERROR");
	//ft_display_node(data.list, 0);
	//ft_display_links(data.links);
	ft_process(&data);
	//ft_display_node(data.list, 1);
	//printf("%d fourmis\n", data.ants);
	ft_display_lines(&data);
	ft_free_lemin(&data);
	return (0);
}
