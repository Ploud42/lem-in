# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 16:22:42 by jsobel            #+#    #+#              #
#    Updated: 2019/01/28 15:11:35 by jsobel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		lem-in
SRC =		main.c			\
			get_next_line.c	\
			check_line.c	\
			process.c		\
			util.c			\
			process_next.c

OBJ		= $(addprefix ./obj/,$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBFTA	= ./libft/libft.a
LIBINCL = -I./libft/includes
LIBLINK	= -L./libft -lft

all: obj libft $(NAME)

obj:
	@mkdir -p ./obj/

./obj/%.o:./src/%.c
	@$(CC) $(CFLAGS) $(LIBINCL) -Iincludes -o $@ -c $<
	@printf "."

libft: $(LIBFTA)

$(LIBFTA):
	@make -C ./libft

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIBLINK)

clean:
	@rm -rf ./obj/
	@make -C ./libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C ./libft fclean

re: fclean all