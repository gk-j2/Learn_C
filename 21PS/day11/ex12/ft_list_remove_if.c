/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:01:17 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/14 16:48:30 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*cur;
	t_list	*prev;
	t_list	*next;

	cur = *begin_list;
	next = cur->next;
	while (cur)
	{
		if ((*cmp)(cur->data, data_ref) == 0)
		{
			prev = cur->next;
			if (cur == *begin_list)
				*begin_list = next;
			free(cur);
			cur = next;
		}
		prev = cur;
		cur = cur->next;
		next = cur->next;
	}
}
