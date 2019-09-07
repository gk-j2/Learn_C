/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 11:28:10 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/09 15:16:29 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_count_words(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i + 1] != '\0')
	{
		if ((str[i] != ' ' && str[i] != '\n' && str[i] != '\t'))
		{
			if (str[i + 1] == ' ' || str[i + 1] == '\n' || str[i + 1] == '\t')
				count++;
		}
		i++;
	}
	count++;
	if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		count--;
	return (count);
}

int		ft_count_char(char *str, int *ptr)
{
	int count_char;
	int i;

	i = *ptr;
	count_char = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
	&& str[i] != '\0')
		i++;
	while ((str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
	&& str[i] != '\0')
	{
		count_char++;
		i++;
	}
	return (count_char);
}

void	ft_strcpy(char *dest, char *str, int *ptr)
{
	int i;
	int j;
	int count;

	count = 0;
	i = *ptr;
	j = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
	&& str[i] != '\0')
	{
		i++;
		count++;
	}
	while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\0')
	{
		dest[j] = str[i];
		j++;
		i++;
		count++;
	}
	dest[j] = '\0';
	*ptr = *ptr + count;
}

char	**ft_split_whitespaces(char *str)
{
	int		temp[4];
	char	**ans;
	char	*copy_str;
	int		*ptr;

	temp[3] = 0;
	ptr = &temp[3];
	copy_str = str;
	temp[1] = ft_count_words(str);
	ans = (char **)malloc(sizeof(char *) * (temp[1] + 1));
	temp[0] = 0;
	while (temp[0] < temp[1])
	{
		temp[2] = ft_count_char(copy_str, ptr);
		ans[temp[0]] = (char *)malloc(sizeof(char) * (temp[2] + 1));
		ft_strcpy(ans[temp[0]], str, ptr);
		temp[0]++;
	}
	ans[temp[0]] = 0;
	return (ans);
}
