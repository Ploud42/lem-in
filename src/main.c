/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:10:14 by jsobel            #+#    #+#             */
/*   Updated: 2019/01/21 17:07:36 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include<stdio.h>

void	ft_display_links(t_link *links)
{
	while (links)
	{
		ft_putstr(links->name1);
		ft_putstr(" connected with ");
		ft_putstr(links->name2);
		write(1, "\n", 1);
		links = links->next;
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
	data.value = 0;
	data.ants = 0;
	data.i = 0;
	while (get_next_line(0, &data.line) > 0 && ft_check_line(&data))
		ft_putendl(data.line);
	ft_display_node(data.list, 0);
	ft_display_links(data.links);
	ft_process(&data);
	ft_display_node(data.list, 1);
	printf("%d fourmis\n", data.ants);
	return (0);
}