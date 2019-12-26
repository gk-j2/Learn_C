/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 20:03:07 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/05 20:06:06 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppeercase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 91)
			i = i + 1;
		else
			return (0);
	}
	return (1);
}
