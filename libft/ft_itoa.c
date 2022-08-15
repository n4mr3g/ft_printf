/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:06:24 by gpiccion          #+#    #+#             */
/*   Updated: 2022/02/02 14:06:24 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Counts digits, including sign (if negative)
static int	ft_count_digits(int number)
{
	int	digit_count;

	digit_count = 1;
	if (number < 0)
	{
		number *= -1;
		digit_count++;
	}
	while (number / 10 >= 1)
	{
		number /= 10;
		digit_count++;
	}
	return (digit_count);
}

// Allocates and returns a string representing the integer 'n'.
// Negative numbers are handled.
// Returns NULL if the allocation fails.
char	*ft_itoa(int n)
{
	size_t			digit_count;
	char			*result;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digit_count = ft_count_digits(n);
	result = malloc(digit_count + 1);
	if (!result)
		return (NULL);
	if (n == 0)
		result[0] = '0';
	else if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	result[digit_count--] = '\0';
	while (n > 0)
	{
		result[digit_count--] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}
