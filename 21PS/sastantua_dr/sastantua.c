/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 08:58:05 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/04 16:07:45 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	ft_putchar(char c)
{write(1, &c, 1);}

void	level(int hight, int length_line)
{
	int i;
	int j;
	int hight_for_space;
	int count_space;

	i  = 0;
	hight_for_space = hight;
	while (i < hight + 1)
	{
		j = count_space = 0;
		while (count_space < hight_for_space)
		{
			ft_putchar(' ');
			count_space = count_space + 1;
		}
		while (j < length_line - 1)
		{
			if (j == 0)
				ft_putchar('/');
			ft_putchar('*');
			j = j + 1;
		if (j == length_line - 1)
			ft_putchar('\\');
		}
		ft_putchar('\n');
		hight_for_space = hight_for_space - 1;
		length_line = length_line + 2;
		i = i + 1;
	}
}

void	sastantua(int size)
{
	int num_of_level;
	int hight;
	int length_line;

	num_of_level = 1;
	hight = 3;
	length_line = 0;
	while (num_of_level <= size)
	{
		level(hight, length_line);
		ft_putchar('\n');
		num_of_level = num_of_level + 1;
		hight = hight + 1;
		length_line +=1;
	}
}

int main()
{
	int size;
	size = 5;
	sastantua(size);
	return (0);
}
