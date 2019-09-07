/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 20:45:40 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/05 20:56:43 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	char *begin;
	int j;

	j = 0;
	begin = dest;
	while (*dest)
		dest++;
	while (src[j] != '\0' && j < nb)
		*dest++ = src[j++];
	*dest = '\0';
	return (begin);
}
