/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 13:12:34 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/11 16:53:06 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int		check_negativ(char **fld)
{
	int i;
	int j;

	i = 1;
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			if (fld[i][j] != '.' && !(fld[i][j] >= '0' && fld[i][j] <= '9'))
					return (-1);
			j++;
		}
		i++;
	};
	return (0);
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int		check_size_line(char **fld)
{
	int		i;

	i = 1;
	while (i < 10)
	{
		if (ft_strlen(fld[i]) != 9)
			return (-1);
		i++;
	}
	return (0);
}

int		check_fld_size(int argc, char **fld)
{
	int error_size_list;

	error_size_list = 0;
	if (argc != 10)
		error_size_list = -1;
	if (check_negativ(fld) != 0)
		error_size_list = -1;
	if (check_size_line(fld) != 0)
		error_size_list = -1;
	return (error_size_list);
}
#include <stdio.h>

#include <stdlib.h> 
#include <stdio.h>
 int main()
{
	int i = 0;
	int error;
		int a = 10;
 char **arr;
 arr = (char **)malloc(sizeof(char *)*3);
 while (i < 10)
	 arr[i++] = (char *)malloc(sizeof(char)*10);
	arr[0] = "main.....";
	arr[1] = "9...7....";
	arr[2] = "2...9..53";
	arr[3] = ".6..124..";
	arr[4] = "84...1.9.";
	arr[5] = "5.....8..";
	arr[6] = ".31..4...";
	arr[7] = "..37..68.";
	arr[8] = ".9..5.741";
	arr[9] = "47.......";
	arr[10]= "47.......";
error = 0;
	error = check_fld_size(a, arr);
	printf("%d", error);
	return (0);
}
