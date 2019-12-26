# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egaylord <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/15 07:00:43 by egaylord          #+#    #+#              #
#    Updated: 2019/08/15 07:04:49 by egaylord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat
C_FILES = main.c
OBJS = main.o
FLAGS = -Wall -Wextra -Werror

all:
		gcc -c $(FLAGS) $(C_FILES)
		gcc $(FLAGS) $(OBJS) -o $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)
