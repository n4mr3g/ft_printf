/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 23:25:20 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/15 19:46:14 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_u(t_printf *pf)
{
	unsigned int	u;
	char			pad;
	int				pad_amount;
	int				prec_amount;
	int				len;

	u = va_arg(pf->args, unsigned int);
	len = get_unsigned_int_len(u);
	if (pf->point && !pf->precision && u == 0)
		len = 0;
	prec_amount = get_prec_amount_u(pf, len);
	pad_amount = get_pad_amount(pf->width, len + prec_amount);
	if (!pad_amount)
	{
		putnbr_format_unsigned(pf, prec_amount, u);
		return ;
	}
	pad = ' ';
	if (pf->zero)
		pad = '0';
	if (!pf->dash)
		pf->total_length += print_repeat(pad, pad_amount);
	putnbr_format_unsigned(pf, prec_amount, u);
	if (pf->dash)
		pf->total_length += print_repeat(pad, pad_amount);
}

void	printf_d(t_printf *pf, int d)
{
	int				pad_amount;
	int				prec_amount;
	int				len;

	len = get_int_len(pf, d);
	if (pf->point && !pf->precision && d == 0)
		len = 0;
	prec_amount = get_prec_amount_int(pf, len, d);
	pad_amount = get_pad_amount(pf->width, len + prec_amount);
	if (pf->zero)
		putnbr_zero(pf, d, pad_amount);
	else
		putnbr_format_signed(pf, d, prec_amount, pad_amount);
}

void	printf_s(t_printf *pf, char *s)
{
	int		len;
	int		pad_amount;

	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (pf->point && pf->precision < len)
		len = pf->precision;
	pad_amount = get_pad_amount(pf->width, len);
	if (!pf->dash)
		pf->total_length += print_repeat(' ', pad_amount);
	pf->total_length += write(1, s, len);
	if (pf->dash)
		pf->total_length += print_repeat(' ', pad_amount);
}

void	printf_c(t_printf *pf)
{
	char	c;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	c = va_arg(pf->args, int);
	if (pf->dash)
		ret += write(1, &c, 1);
	while (i++ < pf->width - 1)
		pf->total_length += write(1, " ", 1);
	if (!pf->dash)
		ret += write(1, &c, 1);
	pf->total_length += ret;
}
