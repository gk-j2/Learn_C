/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 06:56:58 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/19 06:57:17 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	*del_space(char *src, int start, int end)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(sizeof(dest) * (end - start + 1));
	if (dest == 0)
		return (0);
	i = 0;
	while (i < end - start)
	{
		dest[i] = src[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		operation(int a, int b, char operator)
{
	if (operator == '+')
		return (a + b);
	else if (operator == '-')
		return (a - b);
	else if (operator == '*')
		return (a * b);
	else if (operator == '/')
		return (a / b);
	else if (operator == '%')
		return (a % b);
	return (0);
}

int		ft_cut(char *str, char *to_find, int *res)
{
	int i;
	int j;
	int bracket;

	i = ft_strlen(str) - 1;
	bracket = 0;
	while (i >= 0)
	{
		bracket = str[i] == '(' ? bracket + 1 : bracket;
		bracket = str[i] == ')' ? bracket - 1 : bracket;
		j = 0;
		while (to_find[j])
		{
			if (bracket == 0 && str[i] == to_find[j])
			{
				*res = operation(eval_expr(del_space(str, 0, i)),
				eval_expr(del_space(str, i + 1, ft_strlen(str))), to_find[j]);
				return (1);
			}
			j++;
		}
		i--;
	}
	return (0);
}

int		eval_expr(char *str)
{
	int i;
	int res;

	while (str[0] == ' ')
		str = del_space(str, 1, ft_strlen(str));
	while (str[ft_strlen(str) - 1] == ' ')
		str = del_space(str, 0, ft_strlen(str) - 1);
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (ft_atoi(str));
	if (ft_cut(str, "+-", &res))
		return (res);
	if (ft_cut(str, "*/%", &res))
		return (res);
	if (str[0] == '(' && str[ft_strlen(str) - 1] == ')')
		return (eval_expr(del_space(str, 1, ft_strlen(str) - 1)));
	return (0);
}
