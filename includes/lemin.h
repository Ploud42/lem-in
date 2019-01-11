/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:25:08 by jsobel            #+#    #+#             */
/*   Updated: 2019/01/11 17:46:12 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/includes/libft.h"

# define BUFF_SIZE  32

typedef struct		s_data
{
	char			*line;
	char			*tmp;
	int				index;
	struct s_data	*next;
}					t_data;

typedef struct		s_node
{
	char			*name;
	char			**link;
	int				x;
	int				y;
	struct s_node	*next;
}					t_node;

typedef struct		s_lemin
{
	t_node			*list;
	char			*line;
	char			*name;
	char			**tab;
	int				i;
}					t_lemin;

int					ft_check_name(t_lemin *data);
void				ft_check_line(t_lemin *data);

void				ft_exception(char *s);
int					get_next_line(const int fd, char **line);

#endif