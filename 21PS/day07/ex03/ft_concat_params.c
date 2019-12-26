/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 11:50:35 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/08 07:50:48 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_count(int argc, char **argv)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			count++;
			j++;
		}
		count++;
		i++;
	}
	return (count);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		count;
	char	*ans;

	count = ft_count(argc, argv);
	ans = (char *)malloc(sizeof(char)*count);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			*ans = argv[i][j];
			ans++;
			j++;	
		}
		*ans = '\n';
		ans++;
		i++;
	}
	ans--;
	*ans = '\0';
	return (ans - count +1);
}
