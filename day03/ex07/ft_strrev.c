/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:44:28 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/02 22:11:21 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int half;
	int i;
	int j;
	char ch;

	i = 0;
	j = sizeof(str) - 1;
	half = sizeof(str) / 2;
	while (i < half)
	{
		ch = str[i];
		str[i] = str[j];
		str[j] = ch;
		j = j - 1;
		i = i + 1;
	}
	return (str);
}
