/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_argument2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 19:40:59 by tmullan        #+#    #+#                */
/*   Updated: 2020/02/20 19:41:19 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pad_point13(unsigned long x, t_flags *flags, int len, int ul)
{
	if (flags->flag == 3)
		ft_putstrp_fd("0x", 1, 2, flags);
	while (flags->width > len)
	{
		if (flags->flag == 1)
			ft_putcharcount_fd(' ', 1, flags);
		else if (flags->flag == 3)
			ft_putcharcount_fd('0', 1, flags);
		flags->width--;
	}
	if (flags->flag == 1)
		ft_putstrp_fd("0x", 1, 2, flags);
	ft_puthex(x, len, flags, ul);
}

void	pad_point(unsigned long x, t_flags *flags, int len, int ul)
{
	if (flags->flag == 1 || flags->flag == 3)
		pad_point13(x, flags, len, ul);
	else if (flags->flag == 2)
	{
		ft_putstrp_fd("0x", 1, 2, flags);
		ft_puthex(x, len, flags, ul);
		while (flags->width - len > 0)
		{
			ft_putcharcount_fd(' ', 1, flags);
			flags->width--;
		}
	}
	else
	{
		ft_putstrp_fd("0x", 1, 2, flags);
		ft_puthex(x, len, flags, ul);
	}
}
