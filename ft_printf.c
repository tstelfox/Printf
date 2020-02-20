/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 18:09:07 by tmullan        #+#    #+#                */
/*   Updated: 2020/02/20 20:07:50 by tmullan       ########   odam.nl         */
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

void	arg_sort(const char **drip, t_flags *flags, va_list args)
{
	if (**drip == 'd' || **drip == 'i')
		id_handle(args, flags);
	if (**drip == 'c')
		c_handle(args, flags);
	if (**drip == 'u')
		u_handle(args, flags);
	if (**drip == 'X')
		x_handle(args, flags);
	if (**drip == 'x')
		x_handle_low(args, flags);
	if (**drip == 'p')
		p_handle(args, flags);
	if (**drip == 's')
		s_handle(args, flags);
}

void	pad_spacezero(int id, t_flags *flags, int len)
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
		ft_putnbrcount_fd(id, 1, flags);
		while (flags->width - len > 0)
		{
			ft_putcharcount_fd(' ', 1, flags);
			flags->width--;
		}
	}
}

void	pad_psz(t_flags *flags, int len)
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
		while (*drip == '%')
		{
			drip++;
			parser(&flags, &drip, args);
		}
		if (*drip == '\0')
			break ;
		ft_putchar_fd(*drip, 1);
		flags.printed++;
		drip++;
	}
	va_end(args);
	return (flags.printed);
}
