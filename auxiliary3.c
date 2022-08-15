/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 00:22:05 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/15 21:30:46 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Prints the string 'hex_str', which must represent a hexadecimal number.
// Considers width and precision.
void	print_hex_str(t_printf *pf, char *hex_str)
{
	int		prec_amount;
	int		pad_amount;
	int		len;
	char	pad;

	if (pf->zero)
		pad = '0';
	else
		pad = ' ';
	len = ft_strlen(hex_str);
	prec_amount = get_prec_amount_u(pf, len);
	pad_amount = pf->width - prec_amount - len;
	if (!pf->dash)
		pf->total_length += print_repeat(pad, pad_amount);
	pf->total_length += print_repeat('0', prec_amount);
	pf->total_length += write(1, hex_str, len);
	if (pf->dash)
		pf->total_length += print_repeat(' ', pad_amount);
}

// Returns the hexadecimal representation of 'd' as a string.
char	*dec_to_hex(unsigned long d, char mod)
{
	unsigned long			temp;
	char					hex_number[18];
	int						ascii_hex_offset;
	int						i;

	i = 16;
	hex_number[17] = '\0';
	if (mod == 'X')
		ascii_hex_offset = 55;
	else
		ascii_hex_offset = 87;
	if (d == 0)
		hex_number[i--] = '0';
	while (d != 0)
	{
		temp = d % 16;
		if (temp < 10)
			temp = temp + '0';
		else
			temp = temp + ascii_hex_offset;
		hex_number[i--] = (char)temp;
		d = d / 16;
	}
	return (ft_strdup(hex_number + i + 1));
}

// Prints the integer 'd' in the format needed for '0' flag.
void	putnbr_zero(t_printf *pf, int d, int pad_amount)
{
	d = write_sign(pf, d);
	pf->total_length += print_repeat('0', pad_amount);
	pf->total_length += ft_putnbr_signed(d);
}

// Prints the integer 'd', considering formatting flags.
void	putnbr_format_signed(t_printf *pf, int d, int prec_n, int pad_n)
{
	if (!pf->dash)
		pf->total_length += print_repeat(' ', pad_n);
	d = write_sign(pf, d);
	pf->total_length += print_repeat('0', prec_n);
	if (!(pf->point && pf->precision == 0 && d == 0))
		pf->total_length += ft_putnbr_signed(d);
	if (pf->dash)
		pf->total_length += print_repeat(' ', pad_n);
}

// Prints the unsigned int 'u', considering precision.
void	putnbr_format_unsigned(t_printf *pf, int prec_amount, unsigned int u)
{
	pf->total_length += print_repeat('0', prec_amount);
	if (!(pf->point && pf->precision == 0 && u == 0))
			pf->total_length += ft_putnbr_unsigned(u);
}
