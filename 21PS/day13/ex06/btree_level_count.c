/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:42:45 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/16 20:48:53 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int		btree_level_count(t_btree *root)
{
	if (!(root->left) && !(root->right))
		return (1);
	if ((root->left) && !(root->right))
		return (1 + ft_max(btree_level_count(root->left), 0));
	if (!(root->left) && (root->right))
		return (1 + ft_max(0, btree_level_count(root->right)));
	return (1 + ft_max(btree_level_count(root->left),\
btree_level_count(root->right)));
}
