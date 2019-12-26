/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush04.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 12:31:04 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/18 15:21:15 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		valid_first_line_r4(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\n')
	{
		if (buf[i] != 'B' && i != 0 && i != ft_strlen(buf) - 1)
			return (1);
		if (!(buf[0] == 'A' && buf[ft_strlen(buf) - 1] == 'C'))
			return (1);
		i++;
	}
	return (0);
}

int		valid_mid_line_r4(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\n')
	{
		if (buf[i] != ' ' && i != 0 && i != ft_strlen(buf) - 1)
			return (1);
		if (!(buf[0] == 'B' && buf[ft_strlen(buf) - 1] == 'B'))
			return (1);
		i++;
	}
	return (0);
}

int		valid_last_line_r4(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\n')
	{
		if (buf[i] != 'B' && i != 0 && i != ft_strlen(buf) - 1)
			return (1);
		if (!(buf[0] == 'C' && buf[ft_strlen(buf) - 1] == 'A'))
			return (1);
		i++;
	}
	return (0);
}

int		rush04(char *buf, int *ans)
{
	if (ans == 0)
		ans = (int *)malloc(sizeof(int));
	if (!ans)
		return (0);
	if (buf[0] == 'A' && valid_first_line_r4(buf))
		return (-1);
	else if (buf[0] == 'B' && valid_mid_line_r4(buf))
		return (-1);
	else if (buf[0] == 'C' && valid_last_line_r4(buf))
		return (-1);
	if (ans[0] != 0 && ans[0] != ft_strlen(buf))
		return (0);
	else if (ans[0] == 0)
		ans[0] = ft_strlen(buf);
	return (0);
}
