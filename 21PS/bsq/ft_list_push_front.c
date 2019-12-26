/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraynard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:22:00 by lraynard          #+#    #+#             */
/*   Updated: 2019/08/21 13:53:16 by lraynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_list_push_front(t_list **begin_list, char data)
{
	t_list	*crowler;

	crowler = *begin_list;
	if (crowler == 0)
		*begin_list = ft_create_elem(data);
	else
	{
		crowler = ft_create_elem(data);
		crowler->next = *begin_list;
		*begin_list = crowler;
	}
}
