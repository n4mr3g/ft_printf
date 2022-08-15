/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:58:18 by gpiccion          #+#    #+#             */
/*   Updated: 2022/01/31 23:58:18 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Locates the first occurrence of the null-terminated string 'little'
// in the string 'big', where not more than 'len' characters are searched.
// Characters that appear after a ‘\0’ character are not searched.
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;
	int		found;

	if (!*little)
		return ((char *)big);
	little_len = ft_strlen(little);
	i = 0;
	found = -1;
	while (i + little_len <= len && big[i] && found != 0)
	{
		found = ft_strncmp(big + i, little, little_len);
		i++;
	}
	if (found == 0)
		return ((char *)big + i - 1);
	return (NULL);
}
