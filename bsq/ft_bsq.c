/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraynard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 08:50:42 by lraynard          #+#    #+#             */
/*   Updated: 2019/08/22 15:17:48 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_list	*ft_read_to_list(char *av)
{
	int		fd;
	char	buf;
	t_list	*tmp;

	tmp = 0;
	fd = open(av, O_RDONLY | O_RDWR);
	if (fd == -1)
		return (0);
	while (read(fd, &buf, 1))
		ft_list_push_front(&tmp, buf);
	close(fd);
	ft_list_reverse(&tmp);
	return (tmp);
}

void	ft_bsq(char *av)
{
	t_list	*list;
	char	**map;
	char	*c;
	t_parse	*condition;
	t_point	*point;

	list = ft_read_to_list(av);
	c = ft_scan_first_line(&list);
	condition = ft_parse_first_line(c);
	if (ft_test_valid_char(condition, list) ||
		ft_test_num_line(list, condition->num_line))
	{
		write(2, "\nmap error\n", 11);
		return ;
	}
	map = ft_scan_map(list, condition->num_line);
	if (ft_test_num_cul(map, condition->num_line))
	{
		write(2, "\nmap error\n", 11);
		return ;
	}
	ft_cordsetter(map, condition, &point);
	ft_print_map(map, point, condition);
}

void	ft_read_stdin(char *str)
{
	int		fd;
	char	buf;

	fd = open(str, O_RDWR | O_TRUNC, 666);
	if (fd == -1)
	{
		write(2, "\nmap error\n", 11);
		exit(0);
	}
	while (read(0, &buf, 1))
		write(fd, &buf, 1);
	close(fd);
}
