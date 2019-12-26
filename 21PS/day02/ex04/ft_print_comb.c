/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 20:13:44 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/01 19:47:56 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_comb(void)
{
	char ch_digit[3];

	ch_digit[0] = '0';
	while (ch_digit[0] <= '7')
	{
		ch_digit[1] = ch_digit[0] + 1;
		while (ch_digit[1] <= '8')
		{
			ch_digit[2] = ch_digit[1] + 1;
			while (ch_digit[2] <= '9')
			{
				ft_putchar(ch_digit[0]);
				ft_putchar(ch_digit[1]);
				ft_putchar(ch_digit[2]);
				if (ch_digit[0] < 7 || ch_digit[1] < 8 || ch_digit < 9)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				ch_digit[2] = ch_digit[2] + 1;
			}
			ch_digit[1] = ch_digit[1] + 1;
		}
		ch_digit[0] = ch_digit[0] + 1;
	}
}
