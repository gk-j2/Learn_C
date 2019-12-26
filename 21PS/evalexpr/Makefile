# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egaylord <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/17 06:50:24 by egaylord          #+#    #+#              #
#    Updated: 2019/08/18 21:05:46 by egaylord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr
C_FILES = main.c eval_expr.c ft_lib.c
OBJS = main.o eval_expr.o ft_lib.o
FLAGS = -Wall -Wextra -Werror

all:
	gcc -c $(FLAGS) $(C_FILES)
	gcc $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
