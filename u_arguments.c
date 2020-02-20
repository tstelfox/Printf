/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   u_arguments.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 15:26:12 by tmullan        #+#    #+#                */
/*   Updated: 2020/02/20 20:43:22 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pad_uspacezero(unsigned int id, t_flags *flags, int len)
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
		ft_putnbr1_fd(id, 1, flags);
	}
	if (flags->flag == 2)
	{
		ft_putnbr2_fd(id, 1, flags);
		while (flags->width - len > 0)
		{
			ft_putcharcount_fd(' ', 1, flags);
			flags->width--;
		}
	}
}

void	pad_upsz(t_flags *flags, int len)
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
	if (flags->flag == 2)
	{
		while (flags->width - len > 0)
		{
			ft_putcharcount_fd(' ', 1, flags);
			flags->width--;
		}
	}
}

void	pad_unprecision(unsigned int id, t_flags *flags, int len)
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
		ft_putnbr2_fd(id, 1, flags);
	}
}

void	u_precision(unsigned int id, int len, t_flags *flags)
{
	if (!flags->flag)
		pad_unprecision(id, flags, len);
	else
	{
		if (flags->width >= flags->precision)
		{
			if (flags->flag == 2)
			{
				flags->width = (flags->width + len) - flags->precision;
				pad_unprecision(id, flags, len);
				pad_upsz(flags, len);
			}
			else
			{
				flags->width = (flags->width + len) - flags->precision;
				pad_upsz(flags, len);
				pad_unprecision(id, flags, len);
			}
		}
		else
			pad_unprecision(id, flags, len);
	}
}

void	u_handle(va_list args, t_flags *flags)
{
	unsigned int	id;
	int				len;

	id = va_arg(args, unsigned int);
	len = ft_ucount(id);
	if (flags->pflag == 2 && id == 0)
		print_zero(flags);
	else if (flags->pflag == 1)
	{
		if (flags->precision < len && flags->flag)
		{
			if (flags->flag == 3)
				flags->flag = 1;
			pad_uspacezero(id, flags, len);
		}
		else
			u_precision(id, len, flags);
	}
	else if (flags->pflag != 1 && flags->flag)
		pad_uspacezero(id, flags, len);
	else
		ft_putnbr2_fd(id, 1, flags);
}
