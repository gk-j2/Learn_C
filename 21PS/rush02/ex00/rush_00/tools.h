/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amissand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:31:01 by amissand          #+#    #+#             */
/*   Updated: 2019/08/17 15:30:40 by amissand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

char			*ft_draw_line(int x, char start_c, char central_c, char end_c);

unsigned int	ft_strlen(char *str);

void			ft_clear_string(char *str);

char			*append(char *str, char *to_append);

char			*rush(int x, int y, char **tab);

char			*rush00(int x, int y);

char			*rush01(int x, int y);

char			*rush02(int x, int y);

char			*rush03(int x, int y);

char			*rush04(int x, int y);

#endif
