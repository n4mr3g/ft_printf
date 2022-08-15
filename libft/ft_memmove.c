/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:14:03 by gpiccion          #+#    #+#             */
/*   Updated: 2021/11/22 16:14:03 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies 'n' bytes from memory area 'src' to memory area 'dest'.
// The memory areas may overlap.
// First copies into a temporary array, then copies from that array to 'dest'.
// Returns a pointer to 'dest'.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src > dest)
		return (ft_memcpy(dest, src, n));
	while (n-- > 0)
		((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}
