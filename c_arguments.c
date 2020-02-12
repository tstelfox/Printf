/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   c_arguments.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 20:15:20 by tmullan        #+#    #+#                */
/*   Updated: 2020/02/12 13:18:23 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	c_handle(va_list args, t_flags *flags)
{
	int c;
	int len;

	c = va_arg(args, int);
	len = 1;
	if (flags->flag)
		pad_c(c, flags, len);
	else
		ft_putchar_fd(c, 1);
}

void	pad_c(int c, t_flags *flags, int len)
{
	if (flags->flag == 1 || flags->flag == 3)
	{
		while (flags->width > len)
		{
			if (flags->flag == 1)
				ft_putchar_fd(' ', 1);
			else if (flags->flag == 3)
				ft_putchar_fd('0', 1);
			flags->printed++;
			flags->width--;
		}
		ft_putchar_fd(c, 1);
	}
	if (flags->flag == 2)
	{
		ft_putchar_fd(c, 1);
		while (flags->width - len > 0)
		{
			ft_putchar_fd(' ', 1);
			flags->width--;
			flags->printed++;
		}
	}
}
