/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 18:36:43 by tmullan        #+#    #+#                */
/*   Updated: 2020/02/18 17:46:24 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef	struct	s_flags
{
	int	printed;
	int	width;
	int	precision;
	int	arglen;
	int	flag;
	int	pflag;
}				t_flags;

int				ft_printf(const char *drip, ...);
int				ft_count(int n);
int				ft_ucount(unsigned int n);
void			parser(t_flags *flags, const char **drip, va_list args);
void			prec_parser(t_flags *flags, const char **drip, va_list args);
void			arg_sort(const char **drip, t_flags *flags, va_list args);
void			id_handle(va_list args, t_flags *flags);
void			pad_spacezero(int id, t_flags *flags, int len);
void			pad_negative(long id, t_flags *flags, int len);
void			pad_precision(long id, t_flags *flags, int len);
void			ft_putnbr1_fd(long n, int fd, t_flags *flags);
void			ft_putnbr2_fd(unsigned int n, int fd, t_flags *flags);
void			c_handle(va_list args, t_flags *flags);
void			pad_c(int c, t_flags *flags, int len);
void			x_handle(va_list args, t_flags *flags);
void			x_handle_low(va_list args, t_flags *flags);
int				x_count(unsigned int x);
void			ft_puthex(unsigned int x, int len, t_flags *flags, int ul);
void			print_zero(t_flags *flags);
void			pad_psz(int id, t_flags *flags, int len);
void			u_handle(va_list args, t_flags *flags);
void			id_precision(int id, int len, va_list args, t_flags *flags);

#endif

// flag 1 = normal width
// flag 2 = left-justified
// flag 3 = zero-padded

// pflag 1 = precision
// pflag 2 = precision + (0padding or padding)
