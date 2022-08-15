/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 01:06:09 by gpiccion          #+#    #+#             */
/*   Updated: 2022/02/12 01:06:09 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Applies the function 'f' to each character of the string passed as argument,
// and passing its index as first argument.
// Each character is passed by address to 'f' to be modified if necessary.
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}
