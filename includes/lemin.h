/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:25:08 by jsobel            #+#    #+#             */
/*   Updated: 2019/03/06 17:55:48 by jsobel           ###   ########.fr       */
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
# define START		2
# define END		1

typedef struct		s_data
{
	char			*line;
	char			*tmp;
	int				index;
	struct s_data	*next;
}					t_data;

typedef	struct		s_way
{
	char			**tab;
	int				*place;
	int				lenght;
	int				lants;
	struct s_way	*next;
}					t_way;

typedef struct		s_node
{
	char			*name;
	int				value;
	int				weight;
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
	t_node			*p;
	t_link			*links;
	t_link			*t;
	t_way			*way;
	t_way			*l;
	char			*line;
	char			*name;
	t_node			*start;
	t_node			*end;
	uint			ants;
	uint			i;
	int				value;
	int				weight;
	uint			wnbr;
	int				lignemax;
	int				flag;
	char			**tab;
}					t_lemin;

void				ft_free_link(t_lemin *data);
void				ft_free_next(t_lemin *data);
void				ft_free_lemin(t_lemin *data);
void				ft_free_tab(t_lemin *data);

void				ft_gogo(t_lemin *data);
void				ft_display_places(t_lemin *data);
void				ft_display_lines(t_lemin *data);

int					*ft_intmemalloc(size_t size);
int					ft_space_count(char *str);
int					ft_tablen(char **tab);
int					ft_strisdigit(char *str);
uint				ft_atoui(const char *str);

int					ft_lignemax(t_lemin *data);
void				ft_delete_way(t_lemin *data);
void				ft_reset_weight(t_lemin *data);

void				ft_display_ways(t_way *way);
int					ft_connect(t_lemin *data, char *name);
int					ft_save_way(t_lemin *data);
void				ft_put_weight(t_lemin *data, char *name, int weight);
void				ft_process_weight(t_lemin *data);
void				ft_process(t_lemin *data);

void				ft_display_links(t_link *links);
void				ft_display_node(t_node *list, int weight);
int					ft_check_name(t_lemin *data, char *name);
int					ft_check_line(t_lemin *data);

void				ft_exception(char *s);
int					get_next_line(const int fd, char **line);

#endif
