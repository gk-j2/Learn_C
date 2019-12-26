/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_main_attempt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:00:36 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/18 15:55:47 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"


char	*ft_strcpy(char *dest, char *src)
{
	int index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index = index + 1;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		length_src;
	char	*copy;

	length_src = ft_strlen(src);
	copy = (char *)malloc(sizeof(*copy) * (length_src + 1));
	copy = ft_strcpy(copy, src);
	return (copy);
}

#include <stdio.h>
int		main()
{
	char	*buf;
	int		line;
	int		*ans;
	char	*tmp;

	line = 0;
	tmp = (char *)malloc(sizeof(char) * 12);
	ans = (int *)malloc(sizeof(int) * 10);
	read(0, tmp, 11);
	while (line == 0)
	{
		if ((tmp[0] == 'o' &&  tmp[1] == '-') || tmp[0] == '|')
			ans[1] = rush00(tmp, ans);
		else if (buf[0] == '/' || buf[0] == '*' || buf[0] == '\\')
			ans[2] = rush01(tmp, ans);
		else if (buf[0] == 'A' || buf[0] == 'B' || buf[0] == 'C')
		{
			ans[3] = rush02(buf, ans);
			ans[4] = rush03(buf, ans);
			ans[5] = rush04(buf, ans);
		}
		
		line++;
	}
	printf("%d", ans[1]);
		return (0);
}
