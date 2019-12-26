/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:11:54 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/15 19:18:27 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

void	ft_error(char *str);
void	ft_print_err(char *str);
void	ft_print_name(char *str);

#endif
