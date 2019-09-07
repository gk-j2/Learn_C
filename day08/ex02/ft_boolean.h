/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaylord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 07:09:45 by egaylord          #+#    #+#             */
/*   Updated: 2019/08/09 14:18:11 by egaylord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H

# define FT_BOOLEAN_H
# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define EVEN(nbr) ((nbr % 2) == 0 ? 1 : 0)
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_NSG "I have an odd number of arguments.\n"

# include <unistd.h>

typedef int	t_bool;

#endif
