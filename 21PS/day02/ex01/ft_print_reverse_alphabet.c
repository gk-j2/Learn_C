/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_revers_alphabet.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:38:28 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/01 19:53:10 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_reverse_alphabet(void)
{
	char c;

	c = 'z';
	while (c <= 'z')
	{
		ft_putchar(c);
		c = c - 1;
	}
	ft_putchar('\n');
}
