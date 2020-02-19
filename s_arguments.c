/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   s_arguments.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 18:49:57 by tmullan        #+#    #+#                */
/*   Updated: 2020/02/19 23:01:20 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pad_string(char *str, t_flags *flags, int len)
{
	if (flags->width > len)
	{
		if (flags->flag == 1)
		{
			while (flags->width > len)
			{
				ft_putchar_fd(' ', 1);
				flags->width--;
			}
			ft_putstr_fd(str, 1);
		}
		if (flags->flag == 2)
		{
			ft_putstr_fd(str, 1);
			while (flags->width > len)
			{
				ft_putchar_fd(' ', 1);
				flags->width--;
			}
		}
	}
}

void	s_prew(char *str, t_flags *flags, int len)
{
	if (flags->flag == 1)
	{
		while (flags->width > len)
		{
			ft_putchar_fd(' ', 1);
			flags->width--;
		}
		ft_putstrp_fd(str, 1, flags->precision);
	}
	if (flags->flag == 2)
	{
		ft_putstrp_fd(str, 1, flags->precision);
		while (flags->width > len)
		{
			ft_putchar_fd(' ', 1);
			flags->width--;
		}
	}
}

void	s_precision(char *str, t_flags *flags, int len)
{
	if (flags->width > len)
		s_prew(str, flags, len);
	else
	{
		if (flags->precision < len)
			ft_putstrp_fd(str, 1, flags->precision);
		else
			ft_putstr_fd(str, 1);
	}
}

void	s_prewidth(char *str, t_flags *flags, int len)
{
	if (flags->precision > len)
		s_prew(str, flags, len);
	if (flags->precision <= len)
	{
		if (flags->flag == 1)
		{
			while (flags->width > flags->precision)
			{
				ft_putchar_fd(' ', 1);
				flags->width--;
			}
			ft_putstrp_fd(str, 1, flags->precision);
		}
		if (flags->flag == 2)
		{
			ft_putstrp_fd(str, 1, flags->precision);
			while (flags->width > flags->precision)
			{
				ft_putchar_fd(' ', 1);
				flags->width--;
			}
		}
	}
}

/* void	zero_str(char *str, t_flags *flags)
{
	if (!flags->pflag)
	{
		if (flags->width > 6)

		ft_putstr_fd("(null)", 1);
		return ;
	}
	if (flags->precision > 0)
		ft_putstrp_fd(str, 1, flags->precision);
} */

void	s_handle(va_list args, t_flags *flags)
{
	int		len;
	char	*str;

	str = va_arg(args, char *);
	if (str != NULL)
		len = ft_strlen(str);
	else
	{ //This is tomorrow's problem.
		len = 6;
		str = "(null)";
	}
	if (flags->pflag == 2)
		print_zero(flags);
	else if (flags->pflag != 1 && flags->flag && flags->width > len)
		pad_string(str, flags, len);
	else if (flags->pflag == 1)
	{
		if (flags->flag/*  && flags->width > flags->precisio */)
			s_prewidth(str, flags, len);
		else
			s_precision(str, flags, len);
	}
	else
		ft_putstr_fd(str, 1);
}
