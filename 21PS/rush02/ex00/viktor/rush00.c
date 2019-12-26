/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amissand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:42:57 by amissand          #+#    #+#             */
/*   Updated: 2019/08/18 15:24:01 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
    write(1, &c ,1);
}

void	ft_draw_line(int x, char start_c, char central_c, char end_c)
{
	int		i;

	i = 0;
	i++;
	ft_putchar(start_c);
	while (i < x - 1)
	{
		ft_putchar(central_c);
		i++;
	}
	if (x > 1)
	{
		ft_putchar(end_c);
		i++;
	}
	ft_putchar('\n');
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	rush(int x, int y, char **tab)
{
	int		i;

	i = 0;
	if (x <= 0 || y <= 0)
		return ;
	ft_draw_line(x, tab[0][0], tab[0][1], tab[0][2]);
	if (y > 2)
	{
		while (i < y - 2)
		{
			ft_draw_line(x, tab[1][0], tab[1][1], tab[1][2]);
			i++;
		}
	}
	if (y > 1)
		ft_draw_line(x, tab[2][0], tab[2][1], tab[2][2]);
}

void	rush00(int x, int y)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 3);
	if (tab == NULL)
	    return ;
	tab[0] = "o-o";
	tab[1] = "| |";
	tab[2] = "o-o";
	rush(x, y, tab);
}

void	rush01(int x, int y)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 3);
	if (tab == NULL)
	    return ;
	tab[0] = "/*\\";
	tab[1] = "* *";
	tab[2] = "\\*/";
	rush(x, y, tab);
}

void	rush02(int x, int y)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 3);
	if (tab == NULL)
	    return ;
	tab[0] = "ABA";
	tab[1] = "B B";
	tab[2] = "CBC";
	rush(x, y, tab);
}

void	rush03(int x, int y)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 3);
	if (tab == NULL)
	    return ;
	tab[0] = "ABC";
	tab[1] = "B B";
	tab[2] = "ABC";
	rush(x, y, tab);
}

void	rush04(int x, int y)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 3);
	if (tab == NULL)
	    return ;
	tab[0] = "ABC";
	tab[1] = "B B";
	tab[2] = "CBA";
	rush(x, y, tab);
}

int	main(void)
{
    rush00(9, 10);
    return (0);
}
