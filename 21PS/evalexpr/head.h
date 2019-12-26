/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 06:57:22 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/18 21:14:40 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <unistd.h>
# include <stdlib.h>

int					ft_strlen(char *str);
int					eval_expr(char *str);
int					ft_atoi(char *str);
void				ft_putnbr(int nb);
void				ft_putchar(char c);

#endif
