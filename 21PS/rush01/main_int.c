/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 15:08:34 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/10 15:20:15 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_error(void)
{
	write(1, "error", 5);
	return (0);
}


int		main(int argc, char **argv)
{
	int i;
	int j;
	int field[8][8];

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '.')
				field[i - 1][j] = 0;
			else if (argv[i][j] >= 48 && argv[i][j] <= 57)
				field[i - 1][j] = argv[i][j] - 48;
			if (field[i - 1][j] < 0)
				return(ft_error());
		}
	}
}
