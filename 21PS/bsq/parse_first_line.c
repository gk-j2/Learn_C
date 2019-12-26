/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_first_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 06:17:52 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/22 09:19:36 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_parse		*ft_parse_first_line(char *c)
{
	int		arr[2];
	char	*tmp;
	t_parse	*condition;

	if (c == 0)
		return (0);
	arr[0] = ft_strlen(c);
	tmp = (char *)malloc(sizeof(char) * (arr[0] - 2));
	condition = (t_parse *)malloc(sizeof(t_parse));
	arr[1] = 0;
	condition->full = c[arr[0] - 1];
	condition->obs = c[arr[0] - 2];
	condition->empty = c[arr[0] - 3];
	arr[1] = 0;
	while (arr[1] < (arr[0] - 3))
	{
		tmp[arr[1]] = c[arr[1]];
		arr[1]++;
	}
	tmp[arr[1]] = '\0';
	condition->num_line = ft_atoi(tmp);
	free(tmp);
	return (condition);
}
