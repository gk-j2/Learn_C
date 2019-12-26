/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amissand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:29:57 by amissand          #+#    #+#             */
/*   Updated: 2019/08/17 13:35:08 by amissand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_draw_line(int x, char start_c, char central_c, char end_c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc(x + 2);
	if (tmp == NULL)
		return (NULL);
	tmp[i] = start_c;
	i++;
	while (i < x - 1)
	{
		tmp[i] = central_c;
		i++;
	}
	if (x > 1)
	{
		tmp[i] = end_c;
		i++;
	}
	tmp[i] = '\n';
	i++;
	tmp[i] = '\0';
	return (tmp);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void			ft_clear_string(char *str)
{
	str[0] = '\0';
	free(str);
}

char			*append(char *str, char *to_append)
{
	unsigned int	i;
	unsigned int	j;
	char			*tmp;

	tmp = malloc(ft_strlen(str) + ft_strlen(to_append) + 1);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(str))
	{
		tmp[i] = str[i];
		i++;
	}
	ft_clear_string(str);
	j = 0;
	while (j < ft_strlen(to_append))
	{
		tmp[i] = to_append[j];
		i++;
		j++;
	}
	ft_clear_string(to_append);
	tmp[i] = '\0';
	return (tmp);
}

char			*rush(int x, int y, char **tab)
{
	int		i;
	char	*tmp;

	i = 0;
	if (x <= 0 || y <= 0)
		return (NULL);
	tmp = malloc(1);
	if (tmp == NULL)
		return (NULL);
	tmp = append(tmp, ft_draw_line(x, tab[0][0], tab[0][1], tab[0][2]));
	if (y > 2)
	{
		while (i < y - 2)
		{
			tmp = append(tmp, ft_draw_line(x, tab[1][0], tab[1][1], tab[1][2]));
			i++;
		}
	}
	if (y > 1)
		tmp = append(tmp, ft_draw_line(x, tab[2][0], tab[2][1], tab[2][2]));
	return (tmp);
}
