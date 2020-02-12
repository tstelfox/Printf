/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   counters.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 18:15:43 by tmullan        #+#    #+#                */
/*   Updated: 2020/02/12 18:53:03 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	else
	{
		if (n < 0)
			count++;
		while (n < 0 || n > 0)
		{
			n = n / 10;
			count++;
		}
		return (count);
	}
}

void	ft_putnbr1_fd(long n, int fd, t_flags *flags)
{
	if (n < -2147483647)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (flags->pflag == 2 && n == 0)
		ft_putchar_fd(' ', 1);
	else
		ft_putchar_fd(n + '0', fd);
}

int		x_count(int x)
{
	int len;

	len = 0;
	while (x != 0)
	{
		x = x / 16;
		len++;
	}
	if (x == 0)
		return (1);
	return (len);
}

void	ft_puthex(int x, int len, t_flags *flags, int ul)
{
	char	hex[len];
	int		top;
	int		i;

	i = 0;
	while (x != 0)
	{
		top = x % 16;
		if (top < 10)
			top += 48;
		else if (ul == 1)
			top += 55;
		else
			top += 87;
		hex[i] = top;
		i++;
		x /= 16;
	}
	if (x == 0 && flags->pflag == 2)
		ft_putchar_fd(' ', 1);
	else
		x == 0 ? ft_putchar_fd('0', 1) : i--;
	while (i >= 0)
	{
		ft_putchar_fd(hex[i], 1);
		i--;
	}
}