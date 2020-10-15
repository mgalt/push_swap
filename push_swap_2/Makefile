# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 18:09:24 by mgalt             #+#    #+#              #
#    Updated: 2020/10/15 14:04:11 by mgalt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = srcs/error.c \
		srcs/init.c \
		srcs/main.c \
		srcs/pa_pb_rra_rrb_rrr.c \
		srcs/sa_sb_ss_ra_rb_rr.c \
		srcs/ra_rra_num.c \
		srcs/sort.c \
		srcs/sort3.c \
		srcs/sort5.c \
		srcs/utils.c \
		srcs/utils2.c \
		srcs/sort200.c

CC = gcc

LIB = libft

OBJ = $(patsubst %.c,%.o,$(SRC))

CFLAGS = -Wall -Wextra -Werror

LIBFLAGS = -L libft -lft 

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(LIBFLAGS) $^ -o $@

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -I includes -I libft/includes -o $@

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
