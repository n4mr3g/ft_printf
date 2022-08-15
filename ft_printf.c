/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:49:35 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/15 21:15:03 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*printf_init(t_printf *pf)
{
	pf->width = 0;
	pf->alternate = 0;
	pf->precision = 0;
	pf->point = 0;
	pf->dash = 0;
	pf->sign = 0;
	pf->zero = 0;
	pf->space = 0;
	return (pf);
}

int	ft_printf(const char *format, ...)
{
	t_printf			*pf;
	int					ret;
	int					i;

	pf = (t_printf *)malloc(sizeof(t_printf));
	if (!pf)
		return (1);
	pf->total_length = 0;
	va_start(pf->args, format);
	i = 0;
	ret = 0;
	while (format[i])
	{
		printf_init(pf);
		if (format[i] == '%')
			i = printf_get_format(format, i + 1, pf);
		else
			ret += write(1, &format[i], 1);
		i++;
	}
	va_end(pf->args);
	ret += pf->total_length;
	free(pf);
	return (ret);
}
