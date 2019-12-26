/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 15:24:13 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/11 19:11:48 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_line(int y, char *line)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (line[i] == line[y] && i != y && line[i] != '.')
			return (-1);
		i++;
	}
	return (0);
}

int		ft_check_col(int x, int y, char **fld)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (fld[i][y] == fld[x][y] && i != x && fld[i][y] != '.')
			return (-1);
		i++;
	}
	return (0);
}

int		ft_check_square(char **fld)
{
	int i;
	int j;
	int x;
	int y;
	x = 0; y = 0;
	check_value = fld[x][y];
	while (x )
	while (i < 3)
	{
		while (j < 3)
		{
			if (fld[i][j] == fld[x][y] && i != x && j != y)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_control(char **field)
{
	int check[3];
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			check[0] = ft_check_line(i, field[i]);
			if (check[0] == 0)
			{printf("check\n");
				check[1] = ft_check_col(i, j, field);
			}
			else 
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int main()
{
}
