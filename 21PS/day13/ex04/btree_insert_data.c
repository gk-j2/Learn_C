/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 19:45:29 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/16 19:47:23 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	t_btree	*tmp;

	tmp = *root;
	if (*root == 0)
		*root = btree_create_node(item);
	else
	{
		if ((*cmpf)(tmp->item, item) >= 0)
			btree_insert_data(&(tmp->left), item, cmpf);
		else if ((*cmpf)(tmp->item, item) < 0)
			btree_insert_data(&(tmp->right), item, cmpf);
	}
}
