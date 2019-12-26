/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 17:36:42 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/14 16:17:35 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*tmp;

	tmp = begin_list;
	i = nbr;
	while (i > 0 && tmp)
	{
		tmp = tmp->next;
		i--;
	}
	if (tmp)
		return (tmp);
	else
		return (0);
}
