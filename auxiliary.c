/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:27:05 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/15 19:46:03 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Prints the sign of an integer and returns its absolute value.
int	write_sign(t_printf *pf, int d)
{
	if (pf->space && d >= 0)
		pf->total_length += write(1, " ", 1);
	else
	{
		if (pf->sign && d >= 0)
			pf->total_length += write(1, "+", 1);
		else if (d < 0)
		{
			pf->total_length += write(1, "-", 1);
			return (d * -1);
		}
	}
	return (d);
}

// Prints the absolute value of the int 'n'.
// Returns the number of characters written.
int	ft_putnbr_signed(int n)
{
	int	out;

	out = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("2147483648", 1);
		return (10);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
		out++;
	}
	if (n >= 10)
	{
		out += ft_putnbr_signed(n / 10);
		out += ft_putnbr_signed(n % 10);
	}
	else
	{
		ft_putchar_fd((char)n + '0', 1);
		out++;
	}
	return (out);
}

// Returns the number of characters needed to print the integer 'n', 
// including negative sign if n < 0.
int	get_int_len(t_printf *pf, int n)
{
	int	length;

	length = 1;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		n *= -1;
		length++;
	}
	while (n >= 10)
	{
		n /= 10;
		length++;
	}
	if ((pf->sign || pf->space) && n >= 0)
		length++;
	return (length);
}

// Outputs the unsigned int 'n' and returns the number of characters written.
int	ft_putnbr_unsigned(unsigned int n)
{
	int	out;

	out = 0;
	if (n >= 10)
	{
		out += ft_putnbr_unsigned(n / 10);
		out += ft_putnbr_unsigned(n % 10);
	}
	else
	{
		ft_putchar_fd((char)n + '0', 1);
		out++;
	}
	return (out);
}

// Returns the amount of digits of the unsigned int 'n'.
int	get_unsigned_int_len(unsigned int n)
{
	int	length;

	length = 1;
	while (n >= 10)
	{
		n /= 10;
		length++;
	}
	return (length);
}
