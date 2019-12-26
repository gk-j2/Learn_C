/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 09:31:40 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/18 09:52:44 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_rush(int num_of_rush, int cul, int line)
{
	write(1, "[rush-0", 7);
	ft_putnbr(num_of_rush);
	write(1, "] [", 3);
	ft_putnbr(cul);
	write(1, "] [", 3);
	ft_putnbr(line);
	write(1, "]", 1);
}

void	print_log_or(void)
{
	write(1, " || ", 4);
}
