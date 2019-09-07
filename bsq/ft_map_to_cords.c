/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_cords.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraynard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 12:45:43 by lraynard          #+#    #+#             */
/*   Updated: 2019/08/22 09:09:55 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_first_line(int **cords, char **map, t_parse *parse)
{
	int i;

	i = 0;
	while (map[0][i] != '\0')
	{
		if (map[0][i] == parse->obs)
			cords[0][i] = 0;
		if (map[0][i] == parse->empty)
			cords[0][i] = 1;
		i++;
	}
	i = 1;
	while (i < parse->num_line)
	{
		if (map[i][0] == parse->obs)
			cords[i][0] = 0;
		if (map[i][0] == parse->empty)
			cords[i][0] = 1;
		i++;
	}
}

void	ft_max_cord(t_point **point, int i, int j, int value)
{
	(*point)->x = i;
	(*point)->y = j;
	(*point)->value = value;
}

int		ft_else(int **cords, int i, int j)
{
	int min;

	min = cords[i - 1][j];
	if (cords[i - 1][j - 1] < min)
		min = cords[i - 1][j - 1];
	if (cords[i][j - 1] < min)
		min = cords[i][j - 1];
	return (min);
}

void	ft_cordsetter_pre(int **cords, char **map, t_parse *parse,
			t_point **point)
{
	int i;
	int j;

	i = 1;
	j = 1;
	ft_point_init(point);
	while (i < parse->num_line)
	{
		j = 1;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == parse->obs)
				cords[i][j] = 0;
			if (map[i][j] == parse->empty)
			{
				cords[i][j] = ft_else(cords, i, j) + 1;
				if (cords[i][j] > (*point)->value)
					ft_max_cord(point, i, j, cords[i][j]);
			}
			j++;
		}
		i++;
	}
}

void	ft_cordsetter(char **map, t_parse *parse, t_point **point)
{
	int i;
	int **cords;

	i = 0;
	cords = (int **)malloc(sizeof(int *) * parse->num_line);
	while (i < parse->num_line)
	{
		cords[i] = (int *)malloc(sizeof(int) * ft_strlen(map[i]));
		i++;
	}
	ft_first_line(cords, map, parse);
	ft_cordsetter_pre(cords, map, parse, point);
	i = 0;
	while (i < parse->num_line)
	{
		free(cords[i]);
		i++;
	}
	free(cords);
}
