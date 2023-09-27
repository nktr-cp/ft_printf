# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 16:37:53 by knishiok          #+#    #+#              #
#    Updated: 2023/09/28 05:21:19 by knishiok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
ARFLAGS = rc
SRCS = srcs/ft_printf.c \
	srcs/helper1.c \
	srcs/helper2.c \
	srcs/helper3.c \
	srcs/helper4.c \
	srcs/printf_parse.c \
	srcs/print_c_s_percent.c \
	srcs/print_d_i.c \
	srcs/print_u.c \
	srcs/print_x.c

OBJS = $(SRCS:.c=.o)

INC = -I .

all: $(NAME)

bonus: all

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
