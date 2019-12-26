/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 06:59:25 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/13 16:49:10 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_mul(int first_arg, int second_arg);
int		ft_div(int first_arg, int second_arg);
int		ft_mod(int first_arg, int second_arg);
int		ft_add(int first_arg, int second_arg);
int		ft_sub(int first_arg, int second_arg);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);
int		ft_operator(char *argv);
typedef int	(*t_fun)(int, int);
void	check_null(int check, int first_arg, int second_arg, t_fun *arr_f);

int		main(int argc, char **argv)
{
	int		ans;
	int		first_arg;
	int		second_arg;
	t_fun	arr_f[5];

	arr_f[0] = ft_add;
	arr_f[1] = ft_sub;
	arr_f[2] = ft_mul;
	arr_f[3] = ft_div;
	arr_f[4] = ft_mod;
	if (argc != 4)
		return (0);
	first_arg = ft_atoi(argv[1]);
	second_arg = ft_atoi(argv[3]);
	check_null(ft_operator(argv[2]), first_arg, second_arg, arr_f);
	if (ft_operator(argv[2]) == 5)
		write(1, "0", 1);
	if ((ft_operator(argv[2]) != 3 || ft_operator(argv[2]) != 4) &&\
	second_arg != 0 && ft_operator(argv[2]) != 5)
	{
		ans = arr_f[ft_operator(argv[2])](first_arg, second_arg);
		ft_putnbr(ans);
	}
	write(1, "\n", 1);
	return (0);
}

void	ft_putnbr(int nb)
{
	char s;

	if (nb == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		nb = 147483648;
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		s = nb + '0';
		write(1, &s, 1);
	}
}

int		ft_atoi(char *str)
{
	int i;
	int n;
	int flag;

	n = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i = i + 1;
	flag = 1;
	if (str[i] == '-')
	{
		flag = -1;
		i = i + 1;
	}
	else if (str[i] == '+')
		i = i + 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = 10 * n + (str[i] - '0');
		i = i + 1;
	}
	return (n * flag);
}

int		ft_operator(char *argv)
{
	if (argv[0] == '*' && argv[1] == '\0')
		return (2);
	else if (argv[0] == '/' && argv[1] == '\0')
		return (3);
	else if (argv[0] == '%' && argv[1] == '\0')
		return (4);
	else if (argv[0] == '+' && argv[1] == '\0')
		return (0);
	else if (argv[0] == '-' && argv[1] == '\0')
		return (1);
	else
		return (5);
}

void	check_null(int check, int first_arg, int second_arg, t_fun *arr_f)
{
	if (check == 3 && second_arg == 0)
		write(1, "Stop : division by zero", 23);
	if (check == 4 && second_arg == 0)
		write(1, "Stop : modulo by zero", 21);
	if (check == 0 && second_arg == 0)
	{
		ft_putnbr(arr_f[0](first_arg, second_arg));
	}
	if (check == 1 && second_arg == 0)
	{
		ft_putnbr(arr_f[1](first_arg, second_arg));
	}
	if (check == 2 && second_arg == 0)
	{
		ft_putnbr(arr_f[2](first_arg, second_arg));
	}
}
