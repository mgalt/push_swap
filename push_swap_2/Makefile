# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 18:09:24 by mgalt             #+#    #+#              #
#    Updated: 2020/10/15 22:18:29 by mgalt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP_NAME = push_swap

CHECKER_NAME = checker

CHECKER_SRC = srcs/error.c \
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
		srcs/sort200.c \
		srcs/sort_b.c \
		srcs/rb_rrb_num.c \
		srcs/sort800.c 

PS_SRC = srcs/error.c \
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
		srcs/sort200.c \
		srcs/sort_b.c \
		srcs/rb_rrb_num.c \
		srcs/sort800.c 

CC = gcc

LIB = libft

PS_OBJ = $(patsubst %.c,%.o,$(PS_SRC))

CHECKER_OBJ = $(patsubst %.c,%.o,$(CHECKER_SRC))

CFLAGS = -Wall -Wextra -Werror

LIBFLAGS = -L libft -lft 

#all: $(NAME)

#$(NAME): $(OBJ)
#	@make -C libft
#	@$(CC) $(LIBFLAGS) $^ -o $@

#%.o: %.c
#	@$(CC) $(CFLAGS) -c $< -I includes -I libft/includes -o $@

all: $(CHECKER_NAME)

$(CHECKER_NAME): $(PS_OBJ) $(CHECKER_OBJ)
	make -C libft
	@$(CC) $(LIBFLAGS) $^ -o $@

	@echo "\033[33mcreating the checker executable!\033[0m"
	$(CC) $(CFLAGS) -I includes -I libft/includes libft/libft.a $(CHECKER_SRC) -o $(CHECKER_NAME)
	@echo "\033[33mcreating the push swap executable!\033[0m"
	$(CC) $(CFLAGS) -I includes -I libft/includes libft/libft.a $(PS_SRC) -o $(PUSH_SWAP_NAME)

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
