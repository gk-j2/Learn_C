/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraynard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:40:33 by lraynard          #+#    #+#             */
/*   Updated: 2019/08/22 10:41:24 by lraynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			ft_error(t_list *list)
{
	int count;

	count = 0;
	while (list && count < 1)
	{
		if (list->data == '\n')
			count++;
		list = list->next;
	}
	if (count == 0)
		return (1);
	return (0);
}

char		*ft_scan_first_line(t_list **list)
{
	t_list		*arr[2];
	int			count[2];
	char		*c;

	if ((*list) == 0 || ft_error(*list) == 1)
		return (0);
	count[0] = 0;
	count[1] = 0;
	arr[0] = *list;
	arr[1] = *list;
	while (arr[0]->data != '\n' && arr[0]->data != '\0')
	{
		arr[0] = arr[0]->next;
		count[1]++;
	}
	c = (char *)malloc(sizeof(char ) * count[1] + 1);
	while (count[0] < count[1])
	{
		c[count[0]] = arr[1]->data;
		arr[1] = ((*list)->next);
		free(*list);
		*list = arr[1];
		count[0]++;
	}
	return (c);
}

int			count(t_list **list)
{
	int count;

	(*list) = (*list)->next;
	count = 0;
	while ((*list)->data != '\n')
	{
		(*list) = (*list)->next;
		count++;
	}
	return (count);
}

char		**ft_scan_map(t_list *list, int num_line)
{
	char	**map;
	int		counter[2];
	t_list	*tlis;
	int		c;

	counter[0] = 0;
	tlis = list;
	map = (char **)malloc(sizeof(char *) * num_line);
	while (counter[0] < num_line)
	{
		c = count(&tlis);
		list = list->next;
		map[counter[0]] = (char *)malloc(sizeof(char) * c + 2);
		counter[1] = 0;
		while (counter[1] < c)
		{
			map[counter[0]][counter[1]] = list->data;
			list = list->next;
			counter[1]++;
		}
		map[counter[0]][counter[1]] = '\n';
		map[counter[0]][counter[1] + 1] = '\0';
		counter[0]++;
	}
	return (map);
}
