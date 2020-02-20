/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 14:36:43 by tmullan        #+#    #+#                */
/*   Updated: 2020/02/20 15:07:59 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putcharcount_fd(char c, int fd, t_flags *flags)
{
	write(fd, &c, 1);
	flags->printed++;
}

void	ft_putnbrcount_fd(int n, int fd, t_flags *flags)
{
	if (n < -2147483647)
	{
		ft_putcharcount_fd('-', fd, flags);
		ft_putcharcount_fd('2', fd, flags);
		ft_putnbrcount_fd(147483648, fd, flags);
	}
	else if (n < 0)
	{
		ft_putcharcount_fd('-', fd, flags);
		ft_putnbrcount_fd(-n, fd, flags);
	}
	else if (n > 9)
	{
		ft_putnbrcount_fd(n / 10, fd, flags);
		ft_putnbrcount_fd(n % 10, fd, flags);
	}
	else
		ft_putcharcount_fd(n + '0', fd, flags);
}

void	ft_putnbr1_fd(long n, int fd, t_flags *flags)
{
	if (n < -2147483647)
	{
		ft_putcharcount_fd('-', fd, flags);
		ft_putcharcount_fd('2', fd, flags);
		ft_putnbrcount_fd(147483648, fd, flags);
	}
	else if (n < 0)
	{
		ft_putcharcount_fd('-', fd, flags);
		ft_putnbrcount_fd(-n, fd, flags);
	}
	else if (n > 9)
	{
		ft_putnbrcount_fd(n / 10, fd, flags);
		ft_putnbrcount_fd(n % 10, fd, flags);
	}
	else if (flags->pflag == 2 && n == 0)
		ft_putcharcount_fd(' ', 1, flags);
	else
		ft_putcharcount_fd(n + '0', fd, flags);
}

void	ft_putnbr2_fd(unsigned int n, int fd, t_flags *flags)
{
	if (n > 9)
	{
		ft_putnbrcount_fd(n / 10, fd, flags);
		ft_putnbrcount_fd(n % 10, fd, flags);
	}
	else if (flags->pflag == 2 && n == 0)
		ft_putcharcount_fd(' ', 1, flags);
	else
		ft_putcharcount_fd(n + '0', fd, flags);
}

void	ft_putstrp_fd(char *s, int fd, int len, t_flags *flags)
{
	if (!s)
		return ;
	write(fd, s, len);
	flags->printed += len;
}
