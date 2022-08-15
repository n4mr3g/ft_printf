/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:41:13 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/15 19:46:08 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Returns the amount of precision characters needed to print
// the integer 'd' with 'len' amount of digits.
int	get_prec_amount_int(t_printf *pf, int len, int d)
{
	if (pf->point)
	{
		if (d < 0)
			len--;
		if (pf->precision > len)
			return (pf->precision - len);
	}
	return (0);
}

// Returns the amount of precision characters needed to print
// an unsigned int of 'len' amount of digits.
int	get_prec_amount_u(t_printf *pf, int len)
{
	if (!pf->point)
		return (0);
	if (pf->precision > len)
		return (pf->precision - len);
	return (0);
}

// Returns the length of the padding to be printed.
int	get_pad_amount(int width, int strlen)
{
	if (width >= strlen)
		return (width - strlen);
	return (0);
}

// Prints the character 'c', repeated 'n' times.
// Returns the amount of characters printed.
int	print_repeat(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
		i += write(1, &c, 1);
	return (i);
}
