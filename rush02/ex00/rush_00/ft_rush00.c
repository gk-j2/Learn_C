/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 10:13:06 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/18 15:55:45 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		ft_strlen(char *str)
{
	int check;

	check = 0;
	while (str[check] != '\n' || str[check] != '\0')
		check++;
	return (check);
}

int		valid_first_line_r0(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\n')
	{
		if (buf[i] != '-' && i != 0 && i != ft_strlen(buf) - 1)
			return (1);
		if (!(buf[0] == 'o' && buf[ft_strlen(buf) - 1] == 'o'))
			return (1);
		i++;
	}
	return (0);
}

int		valid_mid_line_r0(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\n')
	{
		if (buf[i] != ' ' && i != 0 && i != ft_strlen(buf) - 1)
			return (1);
		if (!(buf[0] == '|' && buf[ft_strlen(buf) - 1] == '|'))
			return (1);
		i++;
	}
	return (0);
}

int		rush00(char *buf, int *ans)
{
	if (buf[0] == 'o' && valid_first_line_r0(buf))
		return (-1);
	else if (buf[0] == '|' && valid_mid_line_r0(buf))
		return (-1);
	if (ans[0] != 0 && ans[0] != ft_strlen(buf))
		return (-1);
	else if (ans[0] == 0)
		ans[0] = ft_strlen(buf);
	return (5);
}
