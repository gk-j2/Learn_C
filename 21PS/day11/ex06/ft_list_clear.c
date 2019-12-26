/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:54:19 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/14 07:09:33 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list *list;
	t_list *tmp;

	list = *begin_list;
	if (list == NULL)
		return ;
	while (list->next != 0)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	free(list);
	*begin_list = NULL;
}
