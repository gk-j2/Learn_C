/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 21:42:10 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/03 16:47:11 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int factor;

	factor = 0;
	if (nb < 0 || nb >= 13)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	else
		factor = nb * ft_recursive_factorial(nb - 1);
	return (factor);
}
