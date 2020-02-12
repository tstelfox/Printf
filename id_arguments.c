/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   id_arguments.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 13:36:41 by tmullan        #+#    #+#                */
/*   Updated: 2020/02/12 23:46:56 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	id_precision(int id, int len, va_list args, t_flags *flags)
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
				pad_psz(id, flags, len);
			}
			else
			{
				flags->width = (flags->width + len) - flags->precision;
				pad_psz(id, flags, len);
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
			ft_putchar_fd(' ', 1);
			flags->width--;
		}
	}
	else if (flags->width == 0)
		return ;
}

void	id_handle(va_list args, t_flags *flags)
{
	int	id;
	int	len;

	id = va_arg(args, int);
	len = ft_count(id);
	/* printf("What the fuck |%d| |%d| |%d| |%d|", flags->flag, flags->pflag, flags->width, flags->precision); */
	if (flags->pflag == 2 && id == 0/*  && flags->width == 0 */)
		print_zero(flags);
	else if (flags->pflag == 1 || (flags->pflag == 2 && id == 0))
	{
		if (flags->precision < len && flags->flag)
		{
			/* flags->pflag = 0; */
			if (flags->flag == 3)
				flags->flag = 1;
			(id >= 0) ? pad_spacezero(id, flags, len)
			: pad_negative(id, flags, len);
		}
		else
			id_precision(id, len, args, flags);
	}
	else if (id < 0 && flags->flag)
		pad_negative(id, flags, len);
	else if (flags->pflag != 1 && flags->flag)
		pad_spacezero(id, flags, len);
	else
		ft_putnbr_fd(id, 1);
}
