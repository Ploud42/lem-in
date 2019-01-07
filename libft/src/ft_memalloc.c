/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:32:04 by jsobel            #+#    #+#             */
/*   Updated: 2018/06/05 15:15:02 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*temp;

	if (!(temp = malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(temp, size + 1);
	return (temp);
}
