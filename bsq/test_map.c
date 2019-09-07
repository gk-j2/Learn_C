/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_num_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:00:23 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/22 10:47:34 by lraynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_test_num_line(t_list *list, int num_line)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = list;
	while (tmp)
	{
		if (tmp->data == '\n')
			count++;
		tmp = tmp->next;
	}
	if (count - 1 != num_line && num_line != 1)
	{
		return (1);
	}
	return (0);
}

int		ft_test_num_cul(char **map, int num_line)
{
	int len;
	int i;

	len = ft_strlen(map[0]);
	i = 1;
	while (i < num_line)
	{
		if (len != ft_strlen(map[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_test_valid_char(t_parse *c, t_list *l)
{
	if (c == 0)
		return (1);
	while (l)
	{
		if (l->data != c->empty && l->data != '\n' && l->data != c->obs)
			return (1);
		l = l->next;
	}
	return (0);
}
