# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egaylord <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/15 07:00:43 by egaylord          #+#    #+#              #
#    Updated: 2019/08/15 19:56:08 by egaylord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail
C_FILES = main.c ft_error_list.c
OBJS = main.o ft_error_list.o
FLAGS = -Wall -Wextra -Werror

all:
		gcc -c $(FLAGS) $(C_FILES)
		gcc $(FLAGS) $(OBJS) -o $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)
