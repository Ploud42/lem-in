/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:10:14 by jsobel            #+#    #+#             */
/*   Updated: 2019/01/11 18:07:20 by jsobel           ###   ########.fr       */
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
	if (argc > 3)
		ft_exception("too many arguments");
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &data.line) > 0)
	{
		ft_check_line(&data);
		ft_putendl(data.line);
	}
	return (0);
}