/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   s_arguments.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 18:49:57 by tmullan        #+#    #+#                */
/*   Updated: 2020/02/20 15:33:57 by tmullan       ########   odam.nl         */
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
				ft_putcharcount_fd(' ', 1, flags);
				flags->width--;
			}
			ft_putstrp_fd(str, 1, len, flags);
		}
		if (flags->flag == 2)
		{
			ft_putstrp_fd(str, 1, len, flags);
			while (flags->width > len)
			{
				ft_putcharcount_fd(' ', 1, flags);
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
			ft_putcharcount_fd(' ', 1, flags);
			flags->width--;
		}
		ft_putstrp_fd(str, 1, len, flags);
	}
	if (flags->flag == 2)
	{
		ft_putstrp_fd(str, 1, len, flags);
		while (flags->width > len)
		{
			ft_putcharcount_fd(' ', 1, flags);
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
			ft_putstrp_fd(str, 1, flags->precision, flags);
		else
			ft_putstrp_fd(str, 1, len, flags);
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
				ft_putcharcount_fd(' ', 1, flags);
				flags->width--;
			}
			ft_putstrp_fd(str, 1, flags->precision, flags);
		}
		if (flags->flag == 2)
		{
			ft_putstrp_fd(str, 1, flags->precision, flags);
			while (flags->width > flags->precision)
			{
				ft_putcharcount_fd(' ', 1, flags);
				flags->width--;
			}
		}
	}
}

void	s_handle(va_list args, t_flags *flags)
{
	int		len;
	char	*str;

	str = va_arg(args, char *);
	if (str != NULL)
		len = ft_strlen(str);
	else
	{
		len = 6;
		str = "(null)";
	}
	if (flags->pflag == 2)
		print_zero(flags);
	else if (flags->pflag != 1 && flags->flag && flags->width > len)
		pad_string(str, flags, len);
	else if (flags->pflag == 1)
	{
		if (flags->flag)
			s_prewidth(str, flags, len);
		else
			s_precision(str, flags, len);
	}
	else
		ft_putstrp_fd(str, 1, len, flags);
}
