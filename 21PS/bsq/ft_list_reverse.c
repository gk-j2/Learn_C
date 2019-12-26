/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraynard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:40:34 by lraynard          #+#    #+#             */
/*   Updated: 2019/08/21 13:49:46 by lraynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *next;
	t_list *current;
	t_list *prev;

	prev = 0;
	current = *begin_list;
	next = 0;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*begin_list = prev;
}
