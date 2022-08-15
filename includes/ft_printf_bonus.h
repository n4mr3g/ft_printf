/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:47:22 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/15 18:51:15 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct pf
{
	va_list		args;
	int			width;
	int			precision;
	int			point;
	int			dash;
	int			total_length;
	int			sign;
	int			zero;
	int			space;
	int			alternate;
}	t_printf;

// Parser functions
int			printf_get_format(const char *format, int i, t_printf *p);
int			printf_get_flags(const char *format, int i, t_printf *p);
int			printf_get_width(const char *format, int i, t_printf *p);
int			printf_get_precision(const char *format, int i, t_printf *p);
int			printf_get_conversion(const char *format, int i, t_printf *p);

// Conversion functions
void		printf_c(t_printf *pf);
void		printf_s(t_printf *pf, char *s);
void		printf_d(t_printf *pf, int d);
void		printf_u(t_printf *pf);
void		printf_p(t_printf *pf);
void		printf_x(t_printf *pf, unsigned int hex, char x_or_X);

// Auxiliary functions
int			ft_putnbr_signed(int n);
int			ft_putnbr_unsigned(unsigned int n);
void		putnbr_format_signed(t_printf *pf, int d, int prec_n, int pad_n);
void		putnbr_format_unsigned(t_printf *pf, int prec, unsigned int u);
void		putnbr_zero_signed(t_printf *pf, int pad, int d);
int			get_int_len(t_printf *p, int n);
int			get_unsigned_int_len(unsigned int n);
int			write_sign(t_printf *p, int d);
char		*dec_to_hex(unsigned long d, char x);
void		print_hex_str(t_printf *p, char *hex_str);
int			get_prec_amount_int(t_printf *pf, int len, int d);
int			get_prec_amount_u(t_printf *pf, int len);
int			get_pad_amount(int width, int strlen);
int			print_repeat(char c, int n);
void		putnbr_padding(t_printf *pf, int d, int pad_amount);
void		putnbr_precision(t_printf *pf, int d, int pad_amount);
void		putnbr_zero(t_printf *pf, int d, int pad_amount);

// Main function
int			ft_printf(const char *format, ...);

#endif