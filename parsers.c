/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 16:37:23 by tmullan        #+#    #+#                */
/*   Updated: 2020/02/25 16:45:05 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_width(const char **drip, t_flags *flags)
{
	flags->width = ft_atoi(*drip);
	while (**drip >= '0' && **drip <= '9')
		(*drip)++;
}

void	set_precision(const char **drip, t_flags *flags)
{
	flags->precision = ft_atoi(*drip);
	if (flags->precision == 0)
		flags->pflag = 2;
	while (**drip >= '0' && **drip <= '9')
		(*drip)++;
}

void	prec_parser2(t_flags *flags, const char **drip, va_list args)
{
	flags->precision = va_arg(args, int);
	if (flags->precision < 0)
		flags->pflag = 0;
	if (flags->flag == 3 && flags->pflag)
	{
		flags->flag = 1;
		flags->cflag = 1;
	}
	if (flags->precision == 0)
		flags->pflag = 2;
	(*drip)++;
}

void	prec_parser(t_flags *flags, const char **drip, va_list args)
{
	flags->pflag = 1;
	(*drip)++;
	if (**drip == '*')
		prec_parser2(flags, drip, args);
	else if (!ft_isdigit(**drip))
	{
		flags->precision = 0;
		flags->pflag = 2;
	}
	else
	{
		set_precision(drip, flags);
		if (flags->flag == 3)
		{
			flags->flag = 1;
			flags->cflag = 1;
		}
	}
}

void	parser2(t_flags *flags, const char **drip, va_list args)
{
	flags->flag = 1;
	while (**drip == '-')
	{
		flags->flag = 2;
		(*drip)++;
	}
	while (**drip == '0')
	{
		if (flags->flag != 2)
			flags->flag = 3;
		(*drip)++;
	}
	if (**drip == '*')
	{
		flags->width = va_arg(args, int);
		if (flags->width < 0)
		{
			flags->flag = 2;
			flags->width *= -1;
		}
		(*drip)++;
	}
	else if (ft_isdigit((int)**drip))
		set_width(drip, flags);
}
