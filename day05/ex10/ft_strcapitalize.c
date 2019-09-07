/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:25:30 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/05 19:05:29 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_capitalize(char *str)
{
	int i;
	int length;

	i = 1;
	length = 0;
	while (str[length] != '\0')
		length = length + 1;
	while (i < length - 1)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			if (str[i-1] >= '9'  && str[i-1] <= '0')
					if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
						str[i] = str[i] - 32;
		i = i + 1;
	}
}
