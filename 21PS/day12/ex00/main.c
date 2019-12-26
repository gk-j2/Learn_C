/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:11:34 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/15 16:13:33 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	buf;

	if (argc < 2)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	else if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	while (read(fd, &buf, 1))
		write(1, &buf, 1);
	close(fd);
	return (0);
}
