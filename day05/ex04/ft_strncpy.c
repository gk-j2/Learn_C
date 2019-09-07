/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 08:12:53 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/05 09:51:48 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int length;

	length = 0;
	while (src[length] != '\0' && length < n)
	{
		dest[length] = src[length];
		length = length + 1;
	}
	if (length <= n)
	{
		while (length <= n)
		{
			dest[length] = '\0';
			length = length + 1;
		}
	}
	return (dest);
}
