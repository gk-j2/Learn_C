/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:08:29 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/14 08:46:16 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	t_list	*tmp;
	int		size;

	size = 0;
	if (begin_list == 0)
		return (size);
	else
	{
		tmp = begin_list;
		while (tmp->next != 0)
		{
			size++;
			tmp = tmp->next;
		}
	}
	return (size + 1);
}
