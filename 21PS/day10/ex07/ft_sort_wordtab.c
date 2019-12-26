/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:57:11 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/13 07:30:24 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i])
	{
		i = i + 1;
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
	}
	return (s1[i] - s2[i]);
}

int		ft_strlen(char **str)
{
	int len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

void	ft_sort_wordtab(char **tab)
{
	int		i;
	int		j;
	int		size;
	char	*tmp;

	size = ft_strlen(tab);
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j = j + 1;
		}
		i = i + 1;
	}
}
