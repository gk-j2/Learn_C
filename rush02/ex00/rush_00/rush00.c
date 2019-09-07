/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amissand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:42:57 by amissand          #+#    #+#             */
/*   Updated: 2019/08/17 13:35:22 by amissand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tools.h"

char			*rush00(int x, int y)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 3);
	if (tab == NULL)
		return (NULL);
	tab[0] = "o-o";
	tab[1] = "| |";
	tab[2] = "o-o";
	return (rush(x, y, tab));
}

char			*rush01(int x, int y)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 3);
	if (tab == NULL)
		return (NULL);
	tab[0] = "/*\\";
	tab[1] = "* *";
	tab[2] = "\\*/";
	return (rush(x, y, tab));
}

char			*rush02(int x, int y)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 3);
	if (tab == NULL)
		return (NULL);
	tab[0] = "ABA";
	tab[1] = "B B";
	tab[2] = "CBC";
	return (rush(x, y, tab));
}

char			*rush03(int x, int y)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 3);
	if (tab == NULL)
		return (NULL);
	tab[0] = "ABC";
	tab[1] = "B B";
	tab[2] = "ABC";
	return (rush(x, y, tab));
}

char			*rush04(int x, int y)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 3);
	if (tab == NULL)
		return (NULL);
	tab[0] = "ABC";
	tab[1] = "B B";
	tab[2] = "CBA";
	return (rush(x, y, tab));
}
