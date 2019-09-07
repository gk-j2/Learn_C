/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 10:42:27 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/07 12:19:14 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int length;
	int *range;

	if (min >= max)
		return (0);
	length = max - min;
	range = (int *)malloc(sizeof(int) * (length));
	i = 0;
	while (i < length)
	{
		range[i] = min + i;
		i = i + 1;
	}
	return (range);
}
