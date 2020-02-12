/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 18:09:07 by tmullan        #+#    #+#                */
/*   Updated: 2020/02/12 23:47:05 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_to_zero(t_flags *flags)
{
	flags->width = 0;
	flags->precision = 0;
	flags->arglen = 0;
	flags->flag = 0;
	flags->pflag = 0;
}

void	pad_precision(long id, t_flags *flags, int len)
{
	if (flags->pflag == 1)
	{
		if (id < 0)
		{
			ft_putchar_fd('-', 1);
			id *= -1;
			flags->precision++;
			flags->printed++;
		}
		while (flags->precision > len)
		{
			ft_putchar_fd('0', 1);
			flags->precision--;
			flags->printed++;
		}
		ft_putnbr1_fd(id, 1, flags);
	}
}

void	pad_negative(long id, t_flags *flags, int len)
{
	if (flags->flag == 1 || flags->flag == 3)
	{
		if (flags->flag == 3)
		{
			ft_putchar_fd('-', 1);
			id *= -1;
			flags->printed++;
		}
		while (flags->width > len)
		{
			flags->flag == 1 ? ft_putchar_fd(' ', 1) : ft_putchar_fd('0', 1);
			flags->width--;
			flags->printed++;
		}
		ft_putnbr_fd(id, 1);
	}
	if (flags->flag == 2)
	{
		ft_putnbr_fd(id, 1);
		while (flags->width - len > 0)
		{
			ft_putchar_fd(' ', 1);
			flags->width--;
			flags->printed++;
		}
	}
}

void	pad_spacezero(int id, t_flags *flags, int len)
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
		/* if (flags->pflag != 1)
			 */ft_putnbr1_fd(id, 1, flags);
	}
	if (flags->flag == 2)
	{
		/* if (flags->pflag != 1)
			 */ft_putnbr_fd(id, 1);
		while (flags->width - len > 0)
		{
			ft_putchar_fd(' ', 1);
			flags->width--;
			flags->printed++;
		}
	}
}

void	pad_psz(int id, t_flags *flags, int len)
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
		/* if (flags->pflag != 1)
			ft_putnbr1_fd(id, 1, flags); */
	}
	if (flags->flag == 2)
	{
		/* if (flags->pflag != 1)
			ft_putnbr_fd(id, 1); */
		while (flags->width - len > 0)
		{
			ft_putchar_fd(' ', 1);
			flags->width--;
			flags->printed++;
		}
	}
}

int		ft_printf(const char *drip, ...)
{
	va_list	args;
	t_flags	flags;
	int		i;

	i = 0;
	va_start(args, drip);
	flags.printed = 0;
	while (*drip != '\0')
	{
		flags_to_zero(&flags);
		if (*drip == '%')
		{
			drip++;
			parser(&flags, &drip, args);
		}
		ft_putchar_fd(*drip, 1);
		flags.printed++;
		drip++;
	}
	va_end(args);
	return (flags.printed);
}
