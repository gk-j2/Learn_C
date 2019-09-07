# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egaylord <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/14 11:55:27 by egaylord          #+#    #+#              #
#    Updated: 2019/08/14 14:10:40 by egaylord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
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
