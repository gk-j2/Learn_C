/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush0X.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 11:26:42 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/04 14:52:05 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_calc(int x, int y, int i, int j);

void	rush(int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_calc(x, y, i, j);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_calc(int x, int y, int i, int j)
{
	if ((i == 0 && j == 0) || (i == y - 1 && j == x - 1))
		ft_putchar('/');
	else if ((i == y - 1 && j == 0) || (i == 0 && j == x - 1))
		ft_putchar('\\');
	else if ((i != 0 && j == 0) || (i != 0 && j == x - 1))
		ft_putchar('*');
	else if ((i == 0 && j != 0) || (i == y - 1 && j != 0))
		ft_putchar('*');
	else
		ft_putchar(' ');
}
