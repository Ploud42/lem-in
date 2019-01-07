# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/03 16:51:36 by hben-yah          #+#    #+#              #
#    Updated: 2018/10/26 18:34:14 by jsobel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			gcc
NAME	=	libft.a
FILES_SRCS	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
				ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c\
				ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c\
				ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c\
				ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
				ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c\
				ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
				ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
				ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c\
				ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c\
				ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c\
				ft_lstadd.c ft_lstiter.c ft_lstmap.c
DIR_OBJS =		./obj
DIR_SRCS =		./src
DIR_INCL =		./includes
FLAGS_COMP =	-Wall -Wextra -Werror
FLAGS_INCL =	-I $(DIR_INCL)
SRCS =			$(FILES_SRCS:%.c=$(DIR_SRCS)/%.c)
OBJ =			$(FILES_SRCS:%.c=$(DIR_OBJS)/%.o)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p $(DIR_OBJS)
	@$(CC) $(FLAGS_COMP) -c $< -o $@ $(FLAGS_INCL)
	@printf "."

all		:	$(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean	:
			@rm -f $(OBJ)

fclean	:	clean
			@rm -f $(NAME)

re		:	fclean all
