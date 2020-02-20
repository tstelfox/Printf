/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   id_arguments.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 13:36:41 by tmullan        #+#    #+#                */
/*   Updated: 2020/02/20 20:42:27 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	id_precision(int id, int len, t_flags *flags)
{
	if (!flags->flag)
		pad_precision(id, flags, len);
	else
	{
		if (flags->width >= flags->precision)
		{
			if (id < 0)
				flags->width--;
			if (flags->flag == 2)
			{
				flags->width = (flags->width + len) - flags->precision;
				pad_precision(id, flags, len);
				pad_psz(flags, len);
			}
			else
			{
				flags->width = (flags->width + len) - flags->precision;
				pad_psz(flags, len);
				pad_precision(id, flags, len);
			}
		}
		else
			pad_precision(id, flags, len);
	}
}

void	print_zero(t_flags *flags)
{
	if (flags->width > 0)
	{
		while (flags->width > 0)
		{
			ft_putcharcount_fd(' ', 1, flags);
			flags->width--;
		}
	}
	else if (flags->width == 0)
		return ;
}

void	pad_negative(long id, t_flags *flags, int len)
{
	if (flags->flag == 1 || flags->flag == 3)
	{
		if (flags->flag == 3 && id >= -2147483647)
		{
			ft_putcharcount_fd('-', 1, flags);
			id *= -1;
		}
		while (flags->width > len)
		{
			flags->flag == 1 ? ft_putcharcount_fd(' ', 1, flags)
			: ft_putcharcount_fd('0', 1, flags);
			flags->width--;
		}
		ft_putnbrcount_fd(id, 1, flags);
	}
	if (flags->flag == 2)
	{
		ft_putnbrcount_fd(id, 1, flags);
		while (flags->width - len > 0)
		{
			ft_putcharcount_fd(' ', 1, flags);
			flags->width--;
		}
	}
}

void	pad_precision(long id, t_flags *flags, int len)
{
	if (flags->pflag == 1)
	{
		if (id < 0)
		{
			ft_putcharcount_fd('-', 1, flags);
			id *= -1;
			flags->precision++;
		}
		while (flags->precision > len)
		{
			ft_putcharcount_fd('0', 1, flags);
			flags->precision--;
		}
		ft_putnbr1_fd(id, 1, flags);
	}
}

void	id_handle(va_list args, t_flags *flags)
{
	int	id;
	int	len;

	id = va_arg(args, int);
	len = ft_count(id);
	if (flags->pflag == 2 && id == 0)
		print_zero(flags);
	else if (flags->pflag == 1)
	{
		if (flags->precision < len && flags->flag)
		{
			if (flags->flag == 3)
				flags->flag = 1;
			(id >= 0) ? pad_spacezero(id, flags, len)
			: pad_negative(id, flags, len);
		}
		else
			id_precision(id, len, flags);
	}
	else if (id < 0 && flags->flag)
		pad_negative(id, flags, len);
	else if (flags->pflag != 1 && flags->flag)
		pad_spacezero(id, flags, len);
	else
		ft_putnbrcount_fd(id, 1, flags);
}
