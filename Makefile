# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: domelche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 15:13:01 by domelche          #+#    #+#              #
#    Updated: 2018/03/07 19:30:44 by domelche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = $(wildcard src/*.c test.c)

OBJ = $(SRCS:.c=.o)

HEAD = printf.h

CFLAGS = -Wall -Wextra -Werror

CC = gcc

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	@/bin/rm -f src/*.o
	@$(MAKE) clean -C libft

fclean: clean
	@/bin/rm -f $(NAME)
	@$(MAKE) fclean -C libft

test: $(OBJ)
	@$(MAKE) -C libft/
	@$(CC) $(OBJ) -o test libft/libft.a

re: fclean all
