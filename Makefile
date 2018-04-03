# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: domelche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 15:13:01 by domelche          #+#    #+#              #
#    Updated: 2018/03/31 15:17:42 by domelche         ###   ########.fr        #
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
	@$(MAKE) -C libft/
	@ar rc $(NAME) $(OBJ)

clean:
	@$(MAKE) clean -C libft/
	@/bin/rm -f src/*.o

fclean: clean
	@$(MAKE) fclean -C libft/
	@/bin/rm -f $(NAME)

test: $(OBJ)
	@$(MAKE) -C libft/
	@$(CC) $(OBJ) -o test libft/libft.a

re: fclean all
