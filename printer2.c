/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printer2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 19:52:21 by tmullan        #+#    #+#                */
/*   Updated: 2020/02/20 19:52:44 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(char *hex, int i, t_flags *flags)
{
	while (i >= 0)
	{
		ft_putcharcount_fd(hex[i], 1, flags);
		i--;
	}
}

void	ft_puthex(unsigned long x, int len, t_flags *flags, int ul)
{
	char				hex[len];
	unsigned long		top;
	int					i;

	i = 0;
	if (x == 0 && flags->pflag != 2)
	{
		ft_putcharcount_fd('0', 1, flags);
		return ;
	}
	while (x != 0)
	{
		top = x % 16;
		if (top < 10)
			top += 48;
		else if (ul == 1)
			top += 55;
		else if (ul == 0)
			top += 87;
		hex[i] = top;
		i++;
		x /= 16;
	}
	i--;
	print_hex(hex, i, flags);
}

void	ft_puthexi(unsigned int x, int len, t_flags *flags, int ul)
{
	char				hex[len];
	unsigned int		top;
	int					i;

	i = 0;
	if (x == 0 && flags->pflag != 2)
	{
		ft_putcharcount_fd('0', 1, flags);
		return ;
	}
	while (x != 0)
	{
		top = x % 16;
		if (top < 10)
			top += 48;
		else if (ul == 1)
			top += 55;
		else if (ul == 0)
			top += 87;
		hex[i] = top;
		i++;
		x /= 16;
	}
	i--;
	print_hex(hex, i, flags);
}
