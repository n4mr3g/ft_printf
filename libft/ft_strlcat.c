/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:54:28 by gpiccion          #+#    #+#             */
/*   Updated: 2022/01/29 17:54:28 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Concatenates strings (dst + src). At most 'size - strlen(dst) - 1' bytes,
// NUL-terminating the result.
// Returns the total length of the string it tried to create.
// That means, the initial length of 'dst' plus the length of 'src'.
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	i;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dst_size > size)
		return (src_size + size);
	else if (size != 0)
	{
		i = dst_size;
		while (i < size - 1 && src[i - dst_size])
		{
			dst[i] = src[i - dst_size];
			i++;
		}
		dst[i] = '\0';
		return (src_size + dst_size);
	}
	else
	{
		return (src_size);
	}
}
