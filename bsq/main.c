/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraynard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 22:51:13 by lraynard          #+#    #+#             */
/*   Updated: 2019/08/21 23:08:49 by lraynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int argc, char **argv)
{
	int		i;
	char	str[1];

	str[0] = 'a';
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			ft_bsq(argv[i]);
			if (i != argc - 1)
				ft_putchar('\n');
			i++;
		}
	}
	else
	{
		ft_read_stdin(str);
		ft_bsq(str);
	}
	return (0);
}
