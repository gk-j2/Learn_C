/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 21:19:48 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/16 20:49:35 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	t_btree	*tmp;

	tmp = root;
	if (tmp)
	{
		if (cmpf(temp->item, data_ref) > 0)
			return (btree_search_item(temp->left, data_ref, cmpf));
		if (cmpf(temp->item, data_ref) == 0)
			return (temp->item);
		if (cmpf(temp->item, data_ref) < 0)
			return (btree_search_item(temp->right, data_ref, cmpf));
	}
	return (0);
}
