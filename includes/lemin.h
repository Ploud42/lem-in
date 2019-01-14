/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:25:08 by jsobel            #+#    #+#             */
/*   Updated: 2019/01/14 18:53:45 by jsobel           ###   ########.fr       */
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

# define BUFF_SIZE	32
# define ROOM		0
# define START		1
# define END		2

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
	int				x;
	int				y;
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct		s_link
{
	char			*name1;
	char			*name2;
	struct s_link	*next;
}					t_link;

typedef struct		s_lemin
{
	t_node			*list;
	t_link			*links;
	char			*line;
	char			*name;
	char			**tab;
	int				value;
}					t_lemin;

void				ft_display_node(t_node *list);
int					ft_check_name(t_lemin *data, char *name);
void				ft_check_line(t_lemin *data);

void				ft_exception(char *s);
int					get_next_line(const int fd, char **line);

#endif