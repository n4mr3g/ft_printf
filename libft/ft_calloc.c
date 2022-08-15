/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:47:04 by gpiccion          #+#    #+#             */
/*   Updated: 2022/03/11 12:47:04 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates memory for an array of 'nmemb' elements of 'size' bytes each.
// The memory is set to zero.
// If 'nmemb' or 'size' is 0, then calloc() returns either NULL,
// or a unique pointer value that can later be successfully passed to free().
// Returns a void pointer to the allocated memory.
// Returns NULL on error, or when 'nmemb' or 'size' are equal to zero.
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	result = malloc(size * nmemb);
	if (!result)
		return (NULL);
	ft_bzero(result, size * nmemb);
	return (result);
}
