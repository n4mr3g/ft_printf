/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:27:08 by gpiccion          #+#    #+#             */
/*   Updated: 2021/11/21 13:27:08 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Scans the initial 'n' bytes of the memory pointed to by 'str'
// for the first instance of 'c'.
// Returns a pointer to the matching byte, if one is found.
// Otherwise, the result is unspecified.
void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*aux;
	size_t	i;

	i = 0;
	aux = (char *)str;
	while (i < n)
	{
		if (aux[i] == (char)c)
			return ((void *)(aux + i));
		i++;
	}
	return (NULL);
}
