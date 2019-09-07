/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:48:41 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/14 16:17:00 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*tmp;
	t_list	*ans;

	if (ac == 0)
		return (0);
	ans = ft_create_elem(av[0]);
	ans->next = 0;
	i = 1;
	while (i < ac)
	{
		tmp = ans;
		ans = ft_create_elem(av[i]);
		ans->next = tmp;
		i++;
	}
	return (ans);
}
