/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amissand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 09:01:54 by amissand          #+#    #+#             */
/*   Updated: 2019/08/18 15:22:54 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	process_left(int *x)
{
	int		ret;
	char	c;

	ret = read(0, &c, 1);
	if (ret == -1)
		return (0);
	if (c == 'o' || c == '/' || c == 'A')
	{
		(*x)++;
		return (c);
	}
	return ('\0');
}

int		process_center(int *x, char center, char right)
{
	int		ret;
	char	c;

	while (1)
	{
		ret = read(0, &c, 1);
		if (ret == -1)
			return (0);
		if (c == center)
			(*x)++;
		else if (c == right)
		{
			(*x)++;
			ret = read(0, &c, 1);
			if (ret == -1)
				return (0);
			if (c == '\n')
				return (1);
			else
				return (0);
		}
		else
			return (0);
	}
}

int		process_top(char center, char right)
{
	int		ret;
	char	c;
	int		x;
	char	top_left;
	char	center;
	char	right;

	x = 0;
	top_left = process_left(&x);
	if (top_left != '\0')
	{
		if (top_left == 'o')
		{
			right = 'o';
			center = '-';
		}
		ret = read(0, &c, 1);
		if (ret == -1)
			return (-1);
		if (c == right)
		{
			x++;
			ret = read(0, &c, 1);
			if (ret == -1)
				return (-1);
				if (c == '\n')
				return (x);
			else
				return (-1);
		}
		else if (c == center)
		{
			x++;
			if (process_center(&x, center, right))
				return (x);
		else
				return (-1);
		}
		else if (c == '\n')
			return (x);
		else
			return (-1);
	}
	else
		return (-1);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		process(char *str, char left, char center, char right)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (i == 0 && str[i] != left)
			return (0);
		else if (i == (len - 2) && str[i] != right)
			return (0);
		else if (i == (len - 1) && str[i] != '\n')
			return (0);
		else if (i != 0 && i != (len - 2) && i != (len - 1) && str[i] != center)
			return (0);
		i++;
	}
	return (1);
}

int		main(void)
{
	int		x;
	char	*str;
	int		y;
	int		ret;
	int		result;

	x = process_top('-', 'o');
	y = 0;
	if (x != -1)
	{
		y++;
		str = malloc(x + 2);
		while (1)
		{
			ret = read(0, str, x + 1);
			if ((x + 1) != ret)
			{
				printf("строка меньше первой\n");
				break;
			}
			result = process(str, '|', ' ', '|');
			if (result)
				y++;
			else if (process(str, 'o', '-', 'o'))
			{
				y++;
				read(0, str, x + 1);
				if (ft_strlen(str) != 0)
				{
					printf("мусор после последней строчки\n");
					break;
				}
			}
		}
	}
	printf("x= %d, y= %d\n", x, y);
	return (0);
}
