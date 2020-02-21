/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_arguments.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 16:39:12 by tmullan        #+#    #+#                */
/*   Updated: 2020/02/21 18:44:07 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pad_p_p(unsigned long x, t_flags *flags, int len, int ul)
{
	if (flags->pflag == 1)
	{
		ft_putstrp_fd("0x", 1, 2, flags);
		flags->precision += 2;
		while (flags->precision > len)
		{
			ft_putcharcount_fd('0', 1, flags);
			flags->precision--;
		}
		ft_puthex(x, len, flags, ul);
	}
}

void	pad_pointsz(unsigned long x, t_flags *flags, int len, int ul)
{
	flags->precision < flags->width ? len += 2 : len;
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
	{
		ft_putstrp_fd("0x", 1, 2, flags);
		ft_puthex(x, len, flags, ul);
	}
}

void	point_precision(unsigned long x, int len, int ul, t_flags *flags)
{
	if (!flags->flag)
		pad_p_p(x, flags, len, ul);
	else
	{
		if (flags->width >= flags->precision)
		{
			if (flags->flag == 2)
			{
				flags->width = (flags->width + len) - flags->precision;
				pad_p_p(x, flags, len, ul);
				pad_pointsz(x, flags, len, ul);
			}
			else
			{
				flags->width = (flags->width + len) - flags->precision;
				if ((flags->width - flags->precision) <= 2)
					flags->width -= 2;
				pad_pointsz(x, flags, len, ul);
				pad_p_p(x, flags, len, ul);
			}
		}
		else
			pad_p_p(x, flags, len, ul);
	}
}

void	print_pzero(t_flags *flags)
{
	if (flags->width > 0)
	{
		if (flags->flag == 2)
			ft_putstrp_fd("0x", 1, 2, flags);
		while (flags->width > 2)
		{
			ft_putcharcount_fd(' ', 1, flags);
			flags->width--;
		}
		if (flags->flag != 2)
			ft_putstrp_fd("0x", 1, 2, flags);
	}
	else if (flags->width == 0)
		ft_putstrp_fd("0x", 1, 2, flags);
}

void	p_handle(va_list args, t_flags *flags)
{
	unsigned long	x;
	int				len;

	x = va_arg(args, unsigned long);
	len = (xp_count(x) + 2);
	if (flags->pflag == 2 && x == 0)
		print_pzero(flags);
	else if (flags->pflag == 1 || (flags->pflag == 2 && x == 0))
	{
		if (flags->precision < (len - 2) && flags->flag)
		{
			if (flags->flag == 3)
				flags->flag = 1;
			pad_point(x, flags, len, 0);
		}
		else
			point_precision(x, len, 0, flags);
	}
	else if (flags->pflag != 1 && flags->flag)
		pad_point(x, flags, len, 0);
	else
		pad_point(x, flags, len, 0);
}
