/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:10:15 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/12 19:50:32 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_any(char **tab, int (*f)(char *))
{
	int i;

	i = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
