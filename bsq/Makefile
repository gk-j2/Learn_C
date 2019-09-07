NAME = bsq

SRC = ft_bsq.c ft_create_elem.c ft_lib.c ft_list_clear.c ft_list_push_front.c ft_list_reverse.c ft_map_to_cords.c ft_one_dim.c ft_point_init.c ft_print_map.c ft_scan_map.c main.c parse_first_line.c test_map.c

OBJ = test_map.o parse_first_line.o main.o ft_scan_map.o ft_print_map.o ft_point_init.o ft_one_dim.o ft_map_to_cords.o ft_list_reverse.o ft_list_push_front.o ft_list_clear.o ft_lib.o  ft_create_elem.o ft_bsq.o


all :
	gcc -c -Wall -Wextra -Werror $(SRC)
	gcc $(OBJ) -o $(NAME)

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
