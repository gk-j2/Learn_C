/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_attempt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:35:51 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/17 17:23:35 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
	{
		len = len + 1;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	char *begin;

	begin = dest;
	while (*dest)
		dest++;
	while (*dest++ = *src++)
		;
	*dest = '\0';
		return (begin);
}

int		main()
{
	int		i;
	int		bytes;
	char	*buf;
	char	*str;
	char	*tmp;

	str = 0;
	buf = (char *)malloc(sizeof(char) * 1024);
	str = (char *)malloc(sizeof(char) * 1024);
	while ((bytes = read(0, &buf, 1023)))
	{
		buf[bytes] = '\0';
		tmp = (char *)malloc(sizeof(char) * (bytes + ft_strlen(str)));
		if (!str)
			return (0);

		str = ft_strcat(str, buf


	}
}
