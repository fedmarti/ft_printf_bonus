# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 15:01:24 by fedmarti          #+#    #+#              #
#    Updated: 2023/04/02 17:58:30 by fedmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES :=ft_printf.c \
	printf_utils.c \
	printf_utils_2.c \
	printf_utils_3.c \
	ft_itoa.c \
	flag_logic.c \
	string_logic.c 	\
	ft_ultoa_base.c \
	ft_utoa_base.c \
	number_logic.c \
	unsigned_logic.c \
	hex_logic.c 

OBJECTS = $(SOURCES:.c=.o)

CFLAGS += -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)

%.o:%.c
	@gcc $(CFLAGS) -c -I. $< -o $@

bonus: $(NAME)

test: fclean bonus
	gcc -g ./.test/printf_test.c $(NAME) -o ./.test/test
	./.test/test | cat -e
	
clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
