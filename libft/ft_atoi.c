/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:32:58 by gpiccion          #+#    #+#             */
/*   Updated: 2022/01/29 22:32:58 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Converts string to integer. Returns the converted value.
// If no valid conversion could be performed, it returns 0.
int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		number;

	i = 0;
	number = 0;
	sign = 1;
	if (nptr[i] == 0 || nptr[i] == '\e')
		return (0);
	while (!ft_isprint(nptr[i]) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		number = number * 10 + nptr[i] - '0';
		i++;
	}
	return (number * sign);
}
