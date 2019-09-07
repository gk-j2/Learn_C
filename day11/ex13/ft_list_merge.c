/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:51:46 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/14 17:27:13 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*tmp;

	if (*begin_list1 == 0)
		*begin_list1 = begin_list2;
	tmp = *begin_list1;
	while (tmp->next != 0)
		tmp = tmp->next;
	tmp->next = begin_list2;
}
