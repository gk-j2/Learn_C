/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 09:38:20 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/16 11:47:26 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree		*btree_create_node(void *item)
{
	t_btree		*tmp;

	tmp = malloc(sizeof(t_btree));
	tmp->left = 0;
	tmp->right = 0;
	tmp->item = item;
	return (tmp);
}
