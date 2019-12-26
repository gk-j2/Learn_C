/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:39:38 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/15 18:12:29 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void		ft_print_err(char *str)
{
	int i;

	i = 0;
	write(2, "cat: ", 5);
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, ": ", 2);
}

void		ft_error(char *str)
{
	ft_print_err(str);
	if (errno == EPERM)
		write(2, "Operation not permitted\n", 24);
	else if (errno == ENOENT)
		write(2, "No such file or directory\n", 26);
	else if (errno == EIO)
		write(2, "Input/output error\n", 19);
	else if (errno == EBADF)
		write(2, "Bad file descriptor\n", 20);
	else if (errno == EACCES)
		write(2, "Permission denied\n", 18);
	else if (errno == EISDIR)
		write(2, "Is a directory\n", 15);
	else if (errno == ENFILE)
		write(2, "Too many open files in system\n", 30);
	else if (errno == EMFILE)
		write(2, "Input/output error\n", 20);
}

void		ft_stdin(void)
{
	char	buf[30];
	int		bytes;

	bytes = 0;
	while ((bytes = read(0, buf, 29)))
	{
		buf[bytes] = '\0';
		write(1, buf, bytes);
	}
}

void		ft_print_file(char *argv)
{
	char	buf[10];
	int		fd;
	int		bytes;

	errno = 0;
	bytes = 0;
	fd = open(argv, O_RDONLY | O_RDWR);
	if (errno != 0)
	{
		ft_error(argv);
		return ;
	}
	while ((bytes = read(fd, buf, 9)))
	{
		buf[bytes] = '\0';
		write(1, buf, bytes);
	}
	close(fd);
}

int			main(int argc, char **argv)
{
	int i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			ft_print_file(argv[i]);
			i++;
		}
	}
	else
	{
		ft_stdin();
	}
	return (0);
}
