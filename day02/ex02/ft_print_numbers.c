/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:52:45 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/01 19:52:18 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_numbers(void)
{
	char num_char;

	num_char = 48;
	while (num_char <= 57)
	{
		ft_putchar(num_char);
		num_char = num_char + 1;
	}
	ft_putchar('\n');
}
