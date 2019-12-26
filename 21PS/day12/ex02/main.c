/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:15:06 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/15 19:26:27 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		ft_atoi(char *str)
{
	int i;
	int n;
	int flag;

	n = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i = i + 1;
	flag = 1;
	if (str[i] == '+')
	{
		flag = -1;
		i = i + 1;
	}
	else if (str[i] == '-')
		i = i + 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = 10 * n + (str[i] - '0');
		i = i + 1;
	}
	return (n * flag);
}

int		ft_size(char *str)
{
	char	c;
	int		count;
	int		fd;

	errno = 0;
	fd = open(str, O_RDONLY | O_RDWR);
	if (errno != 0)
	{
		if (errno == EISDIR)
		{
			write(2, "==> ", 4);
			ft_print_name(str);
			write(2, " <==\n", 5);
		}
		else
			ft_error(str);
		return (0);
	}
	count = 0;
	while (read(fd, &c, 1))
		count++;
	close(fd);
	return (count);
}

void	ft_tail(int size, int offset, char *str)
{
	int		i;
	int		fd;
	int		count;
	char	c;

	fd = open(str, O_RDONLY | O_RDWR);
	if (errno != 0)
	{
		ft_error(str);
		return ;
	}
	i = 0;
	if (offset > 0)
	{
		count = size - offset;
		while (read(fd, &c, 1))
		{
			if (i >= count)
				write(1, &c, 1);
			i++;
		}
	}
	else
	{
		count = (-1) * offset;
		while (read(fd, &c, 1))
		{
			if ((i >= count))
				write(1, &c, 1);
			i++;
		}
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		size;
	int		offset;

	offset = ft_atoi(argv[2]);
	i = 3;
	while(i < argc)
	{
		size = ft_size(argv[i]);
		ft_tail(size, offset,  argv[i]);
		i++;
	}
}
