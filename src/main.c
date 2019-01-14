/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:10:14 by jsobel            #+#    #+#             */
/*   Updated: 2019/01/14 17:45:33 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include<stdio.h>

void	ft_exception(char *s)
{
	ft_putendl(s);
	exit(EXIT_FAILURE);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_lemin	data;

	data.list = NULL;
	data.value = 0;
	if (argc > 3)
		ft_exception("too many arguments");
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &data.line) > 0)
	{
		ft_check_line(&data);
		ft_putendl(data.line);
	}
	ft_display_node(data.list);
	return (0);
}