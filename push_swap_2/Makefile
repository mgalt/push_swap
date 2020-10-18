# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 18:09:24 by mgalt             #+#    #+#              #
#    Updated: 2020/10/18 19:06:28 by mgalt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CHECKER_NAME = checker

PUSH_SWAP_NAME = push_swap

LIBFT = libft/libft.a

LIBFT_DIR = ./libft/

HEADER = push_swap.h

CHECKER_SOURCES = srcs/checker_src/error.c \
		srcs/checker_src/init.c \
		srcs/checker_src/pa_pb_rra_rrb_rrr.c \
		srcs/checker_src/sa_sb_ss_ra_rb_rr.c \
		srcs/checker_src/ra_rra_num.c \
		srcs/checker_src/utils.c \
		srcs/checker_src/utils2.c \
		srcs/checker_src/rb_rrb_num.c \
		srcs/checker_src/checker_main.c \
		srcs/checker_src/do_op.c

PUSH_SWAP_SOURCES = srcs/push_swap_src/error.c \
		srcs/push_swap_src/init.c \
		srcs/push_swap_src/main.c \
		srcs/push_swap_src/pa_pb_rra_rrb_rrr.c \
		srcs/push_swap_src/sa_sb_ss_ra_rb_rr.c \
		srcs/push_swap_src/ra_rra_num.c \
		srcs/push_swap_src/sort.c \
		srcs/push_swap_src/sort3.c \
		srcs/push_swap_src/sort5.c \
		srcs/push_swap_src/utils.c \
		srcs/push_swap_src/utils2.c \
		srcs/push_swap_src/sort200.c \
		srcs/push_swap_src/sort_b.c \
		srcs/push_swap_src/rb_rrb_num.c \
		srcs/push_swap_src/sort800.c 

OBJ_P_SW = $(patsubst %.c,%.o,$(PUSH_SWAP_SOURCES))

OBJ_CH = $(patsubst %.c,%.o,$(CHECKER_SOURCES))

all: $(PUSH_SWAP_NAME) $(CHECKER_NAME)

$(PUSH_SWAP_NAME): $(LIBFT) $(OBJ_P_SW)
	$(CC) $(CFLAGS) -lft -L libft -I$(HEADER) \ 
	$(OBJ_P_SW) -o $(PUSH_SWAP_NAME)
	echo "\nobject files were created (push_swap)"


$(CHECKER_NAME): $(LIBFT) $(OBJ_CH)
	$(CC) $(CFLAGS) -lft -L libft -I$(HEADER) \
	$(OBJ_CH) -o $(CHECKER_NAME)
	echo "\nobject files were created (checker)"
	   
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $(HEADER) $< -o $@

$(LIBFT):
	make -C libft

clean:
	echo "\033[31mObjects cleaned!\033[0m"
	make -C libft clean
	rm -f $(OBJ_CH)
	rm -f $(OBJ_P_SW)

fclean: clean
	echo "\033[31mExecutables cleaned!\033[0m"
	make -C libft fclean
	rm -f $(CHECKER_NAME)
	rm -f $(PUSH_SWAP_NAME)

re: fclean all