/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   x_argument2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 19:54:28 by tmullan        #+#    #+#                */
/*   Updated: 2020/02/20 19:54:57 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pad_hexsz(unsigned int x, t_flags *flags, int len, int ul)
{
	if (flags->flag == 1 || flags->flag == 3)
	{
		while (flags->width > len)
		{
			if (flags->flag == 1)
				ft_putcharcount_fd(' ', 1, flags);
			else if (flags->flag == 3)
				ft_putcharcount_fd('0', 1, flags);
			flags->width--;
		}
	}
	else if (flags->flag == 2)
	{
		while (flags->width - len > 0)
		{
			ft_putcharcount_fd(' ', 1, flags);
			flags->width--;
		}
	}
	else
		ft_puthexi(x, len, flags, ul);
}
