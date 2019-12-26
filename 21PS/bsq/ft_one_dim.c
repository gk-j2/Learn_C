/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_dim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 07:16:08 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/22 08:44:32 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void			ft_one_dim(char **map, t_parse *parse)
{
	int i;
	int j;

	i = 0;
	while (i < parse->num_line)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == parse->empty)
			{
				map[i][j] = parse->full;
				return ;
			}
			j++;
		}
		i++;
	}
}
