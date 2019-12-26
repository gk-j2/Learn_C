/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:36:20 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/13 15:25:47 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*tmp;

	if (begin_list == 0)
		return (0);
	else
	{
		tmp = begin_list;
		while (tmp->next != 0)
			tmp = tmp->next;
		return (tmp);
	}
}
