# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 15:22:07 by ohayek            #+#    #+#              #
#    Updated: 2023/07/20 15:50:23 by ohayek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
LIBDIR	= libft/libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

SRCS	= error.c free.c init.c linked_list.c main.c min_max.c radix.c sort_moves_1.c\
		  sort_moves_2.c sort_moves_3.c tiny_sorts.c
OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(SRCS) $(LIBDIR)
	$(CC) $(SRCS) $(LIBDIR) -o $(NAME) $(CFLAGS)

$(LIBDIR):
	@make -C libft/
	@echo "compiled libft.a\n"

clean:
	$(RM) $(OBJS)
	@make clean -C libft/

fclean: clean
	$(RM) $(NAME)
	
	@make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re