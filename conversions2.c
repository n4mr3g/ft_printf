/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 23:13:20 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/15 19:46:17 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_p(t_printf *pf)
{
	unsigned long long	p;
	char				*temp;
	char				*hex_string;

	p = va_arg(pf->args, unsigned long long);
	temp = dec_to_hex((unsigned long)p, 'x');
	hex_string = ft_strjoin("0x", temp);
	print_hex_str(pf, hex_string);
	free(hex_string);
	free(temp);
}

void	printf_x(t_printf *pf, unsigned int hex_n, char x_or_X)
{
	char	*hex_str;
	char	*temp;

	if (pf->point && !pf->precision && hex_n == 0)
	{
		print_hex_str(pf, "");
		return ;
	}
	temp = dec_to_hex(hex_n, x_or_X);
	if (pf->alternate && hex_n != 0)
	{
		if (x_or_X == 'x')
			hex_str = ft_strjoin("0x", temp);
		else
			hex_str = ft_strjoin("0X", temp);
		free(temp);
	}
	else
		hex_str = temp;
	print_hex_str(pf, hex_str);
	free(hex_str);
}
