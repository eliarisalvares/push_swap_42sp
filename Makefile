# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 16:11:46 by elraira-          #+#    #+#              #
#    Updated: 2022/03/30 20:24:30 by elraira-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[32m
BLUE = \033[34m
YELLOW = \e[0;33m
RESET = \033[0m

NAME	=	push_swap

CFLAGS = -Wall -Wextra -Werror
CC = gcc

INC = -Iincludes/ -Ilibft/ \

LIBS = -Llibft -lft

SRCS	=	operations/swap_operations.c operations/rotate_operations.c \
			operations/reverse_rotate_operations.c \
			operations/push_operations.c main.c validation_functions.c \
			push_swap.c frees.c simple_sorting_functions.c linked_list_utils.c \
			init_stack.c

OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	${OBJS}
			$(MAKE) -sC libft
			$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

.c.o	:
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean	:
	$(MAKE) -sC libft clean
	rm -f $(OBJS)

fclean	:
	$(MAKE) -sC libft fclean
	rm -f $(OBJS) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
