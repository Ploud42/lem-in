/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:05:57 by jsobel            #+#    #+#             */
/*   Updated: 2019/02/20 18:53:37 by juliensobel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include<stdio.h>

void	ft_gogo(t_lemin *data)
{
	int i;

	data->l = data->way;
	while (data->l)
	{
		i = data->l->lenght - 1;
		while (i >= 1)
		{
			data->l->place[i] = data->l->place[i - 1];
			i--;
		}
		data->l->place[0] = 0;
		data->l = data->l->next;
	}
}

void	ft_display_places(t_lemin *data)
{
	int i;

	data->l = data->way;
	while (data->l)
	{
		i = 0;
		while (i < data->l->lenght)
		{
			//printf("i = %d, lenght = %d\n", i, data->l->lenght);
			if (data->l->place[i])
			{
				if (data->flag)
					write(1, " ", 1);
				data->flag = 1;
				write(1, "L", 1);
				ft_putnbr(data->l->place[i]);
				write(1, "-", 1);
				ft_putstr(data->l->tab[i]);
			}
			i++;
		}
		data->l = data->l->next;
	}
	if (data->flag)
		write(1, "\n", 1);
}

void	ft_display_lines(t_lemin *data)
{
	data->flag = 1;
	data->i = 1;
	while (data->flag)
	{
		data->flag = 0;
		data->l = data->way;
		while (data->l)
		{
			if (data->i <= data->ants && !data->l->place[0] &&
			data->l->lants > data->l->lenght && data->l->lants--)
			{
				data->l->place[0] = data->i;
				data->i++;
			}
			data->l = data->l->next;
		}
		ft_display_places(data);
		ft_gogo(data);
	}
}
