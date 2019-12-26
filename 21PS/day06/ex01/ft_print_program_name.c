/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:44:45 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/06 16:58:02 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int i;
	int n;

	n = argc;
	i = 0;
	while (argv[0][i] != '\0')
	{
		ft_putchar(argv[0][i]);
		i = i + 1;
	}
	return (0);
}
