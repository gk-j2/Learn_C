# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egaylord <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/17 09:13:32 by egaylord          #+#    #+#              #
#    Updated: 2019/08/17 09:25:05 by egaylord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2
C_FILES = srcs/*.c
INCL = includes/*.h
FLAGS = -Wall -Wextra -Werror

all:
		gcc -I $(INCL) $(FLAGS) $(C_FILES) -o $(NAME)

fclean:
		rm -rf $(NAME)
