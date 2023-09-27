# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 16:37:53 by knishiok          #+#    #+#              #
#    Updated: 2023/09/26 11:45:56 by knishiok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
ARFLAGS = rc
SRCS = srcs/ft_printf.c \
	srcs/helper1.c \
	srcs/helper2.c \
	srcs/helper3.c \
	srcs/printf_parse.c \
	srcs/print_helper1.c \
	srcs/print_helper2.c

OBJS = $(SRCS:.c=.o)

INC = -I .

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
