/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   x_arguments.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 13:21:51 by tmullan        #+#    #+#                */
/*   Updated: 2020/02/20 19:55:49 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pad_hex(unsigned int x, t_flags *flags, int len, int ul)
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
		ft_puthexi(x, len, flags, ul);
	}
	else if (flags->flag == 2)
	{
		ft_puthexi(x, len, flags, ul);
		while (flags->width - len > 0)
		{
			ft_putcharcount_fd(' ', 1, flags);
			flags->width--;
		}
	}
	else
		ft_puthexi(x, len, flags, ul);
}

void	pad_hex_p(unsigned int x, t_flags *flags, int len, int ul)
{
	if (flags->pflag == 1)
	{
		while (flags->precision > len)
		{
			ft_putcharcount_fd('0', 1, flags);
			flags->precision--;
		}
		ft_puthexi(x, len, flags, ul);
	}
}

void	hex_precision(unsigned int x, int len, int ul, t_flags *flags)
{
	if (!flags->flag)
		pad_hex_p(x, flags, len, ul);
	else
	{
		if (flags->width >= flags->precision)
		{
			if (flags->flag == 2)
			{
				flags->width = (flags->width + len) - flags->precision;
				pad_hex_p(x, flags, len, ul);
				pad_hexsz(x, flags, len, ul);
			}
			else
			{
				flags->width = (flags->width + len) - flags->precision;
				pad_hexsz(x, flags, len, ul);
				pad_hex_p(x, flags, len, ul);
			}
		}
		else
			pad_hex_p(x, flags, len, ul);
	}
}

void	x_handle(va_list args, t_flags *flags)
{
	int x;
	int len;

	x = va_arg(args, unsigned int);
	len = x_count(x);
	if (flags->pflag == 2 && x == 0)
		print_zero(flags);
	else if (flags->pflag == 1)
	{
		if (flags->precision < len && flags->flag)
		{
			if (flags->flag == 3)
				flags->flag = 1;
			pad_hex(x, flags, len, 1);
		}
		else
			hex_precision(x, len, 1, flags);
	}
	else if (flags->pflag != 1 && flags->flag)
		pad_hex(x, flags, len, 1);
	else
		ft_puthexi(x, len, flags, 1);
}

void	x_handle_low(va_list args, t_flags *flags)
{
	int x;
	int len;

	x = va_arg(args, unsigned int);
	len = x_count(x);
	if (flags->pflag == 2 && x == 0)
		print_zero(flags);
	else if (flags->pflag == 1 || (flags->pflag == 2 && x == 0))
	{
		if (flags->precision < len && flags->flag)
		{
			if (flags->flag == 3)
				flags->flag = 1;
			pad_hex(x, flags, len, 0);
		}
		else
			hex_precision(x, len, 0, flags);
	}
	else if (flags->pflag != 1 && flags->flag)
		pad_hex(x, flags, len, 0);
	else
		pad_hex(x, flags, len, 0);
}
