/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:09:30 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/15 19:17:51 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_print_name(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	ft_print_err(char *str)
{
	write(2, "tail: ", 6);
	ft_print_name(str);
	write(2, ": ", 2);
}

void	ft_error(char *str)
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
	else if (errno == ENFILE)
		write(2, "Too many open files in system\n", 30);
	else if (errno == EMFILE)
		write(2, "Input/output error\n", 20);
}
