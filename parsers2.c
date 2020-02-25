/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsers2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 16:43:58 by tmullan        #+#    #+#                */
/*   Updated: 2020/02/25 16:44:53 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parser(t_flags *flags, const char **drip, va_list args)
{
	while ((**drip >= '0' && **drip <= '9') || **drip == '-' || **drip == '*')
		parser2(flags, drip, args);
	if (**drip == '.')
		prec_parser(flags, drip, args);
	if (ft_isalpha((int)**drip) || **drip == '%')
		arg_sort(drip, flags, args);
	else
		return ;
	(*drip)++;
}
