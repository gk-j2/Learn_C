/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 09:36:56 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/03 19:49:08 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int i;
	int factor;

	if (nb < 0 || nb >= 13)
		return (0);
	i = 1;
	factor = 1;
	while (i <= nb)
	{
		factor = factor * i;
		i = i + 1;
	}
	return (factor);
}
