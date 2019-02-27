/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:41:01 by jsobel            #+#    #+#             */
/*   Updated: 2019/02/27 17:56:28 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*c;

	i = 0;
	while (s[i])
		i++;
	if (!(c = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s[++i])
		c[i] = s[i];
	c[i] = 0;
	return (c);
}
