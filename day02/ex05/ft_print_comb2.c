/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 06:50:28 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/01 19:48:48 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char fir_one, char sec_one, char fir_two, char sec_two);
void	ft_main(char fir_one, char sec_one, char fir_two, char sec_two);
int		ft_putchar(char c);

void	ft_print_comb2(void)
{
	char fir_one;
	char sec_one;
	char fir_two;
	char sec_two;

	fir_one = '0';
	sec_one = '0';
	fir_two = '0';
	sec_two = '0';
	ft_main(fir_one, sec_one, fir_two, sec_two);
}

void	ft_main(char fir_one, char sec_one, char fir_two, char sec_two)
{
	fir_one = '0';
	while (fir_one <= '9')
	{
		sec_one = '0';
		while (sec_one <= '9')
		{
			fir_two = fir_one;
			while (fir_two <= '9')
			{
				sec_two = sec_one + 1;
				while (sec_two <= '9')
				{
					ft_print(fir_one, sec_one, fir_two, sec_two);
					sec_two = sec_two + 1;
				}
				fir_two = fir_two + 1;
			}
			sec_one = sec_one + 1;
		}
		fir_one = fir_one + 1;
	}
}

void	ft_print(char fir_one, char sec_one, char fir_two, char sec_two)
{
	ft_putchar(fir_one);
	ft_putchar(sec_one);
	ft_putchar(' ');
	ft_putchar(fir_two);
	ft_putchar(sec_two);
	if (fir_one == '9' && sec_one == '8')
	{
		ft_putchar('\0');
	}
	else
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}
