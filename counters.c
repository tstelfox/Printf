/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   counters.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 18:15:43 by tmullan        #+#    #+#                */
/*   Updated: 2020/02/20 19:53:45 by tmullan       ########   odam.nl         */
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

int		ft_ucount(unsigned int n)
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

int		x_count(unsigned long x)
{
	int len;

	len = 0;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x = x / 16;
		len++;
	}
	return (len);
}
