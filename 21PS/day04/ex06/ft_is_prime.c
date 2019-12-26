/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 07:32:06 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/03 20:00:43 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;

	if (nb <= 1)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	else
	{
		i = 5;
		while (i * i <= nb)
		{
			if (nb % i == 0 || nb % (i + 2) == 0)
				return (0);
			i = i + 6;
		}
	}
	return (1);
}