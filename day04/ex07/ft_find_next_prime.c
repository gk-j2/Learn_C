/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:42:23 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/03 16:21:21 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int isPrime(int nb) {
	while (i < nb)
	{
		if (nb % i == 0)
			ans = ans + 1;
		i = i + 1;
	}
	if (ans == 0)
		return (nb);
	else
	{
		ans = 0;
		i = 2;
		nb = nb + 1;
	}

}

int		ft_find_next_prime(int nb)
{
	int i;
	int ans;

	if (nb <= 2)
		return (2);
	if (nb == 3)
		return (3);
	while (isPrime(nb))
	{
		nb++;
	}
	return (nb)
}
