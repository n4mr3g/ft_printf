/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_eval.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 23:16:36 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/15 19:46:20 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_get_conversion(const char *format, int i, t_printf *pf)
{
	if (format[i] == 's')
		printf_s(pf, va_arg(pf->args, char *));
	else if (format[i] == 'c')
		printf_c(pf);
	else if (format[i] == 'p')
		printf_p(pf);
	else if (format[i] == 'd' || format[i] == 'i')
		printf_d(pf, va_arg(pf->args, int));
	else if (format[i] == 'u')
		printf_u(pf);
	else if (format[i] == 'x' || format[i] == 'X')
		printf_x(pf, (unsigned long)va_arg(pf->args, void *), format[i]);
	else if (format[i] == '%')
		pf->total_length += write(1, "%", 1);
	return (i);
}

int	printf_get_precision(const char *format, int i, t_printf *pf)
{
	if (format[i] == '.')
	{
		pf->zero = 0;
		pf->point = 1;
		i++;
		if (!ft_isdigit(format[i]))
			return (i);
		while (ft_isdigit(format[i]))
		{
			pf->precision = pf->precision * 10 + (format[i] - '0');
			i++;
		}
	}
	return (i);
}

int	printf_get_width(const char *format, int i, t_printf *pf)
{
	while (ft_isdigit(format[i]))
	{
		pf->width = pf->width * 10 + (format[i] - '0');
		i++;
	}
	return (i);
}

int	printf_get_flags(const char *format, int i, t_printf *pf)
{
	while (ft_strchr("-+# 0", format[i]))
	{
		if (format[i] == '-')
			pf->dash = 1;
		else if (format[i] == '+')
			pf->sign = 1;
		else if (format[i] == '#')
			pf->alternate = 1;
		else if (format[i] == ' ' && !pf->sign)
			pf->space = 1;
		else if (format[i] == '0' && !pf->dash)
			pf->zero = 1;
		i++;
	}
	if (pf->dash && (pf->zero || pf->point))
		pf->zero = 0;
	if (pf->sign && pf->space)
		pf->space = 0;
	return (i);
}

int	printf_get_format(const char *format, int i, t_printf *pf)
{
	i = printf_get_flags(format, i, pf);
	i = printf_get_width(format, i, pf);
	i = printf_get_precision(format, i, pf);
	i = printf_get_conversion(format, i, pf);
	return (i);
}
