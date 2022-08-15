/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 03:00:21 by gpiccion          #+#    #+#             */
/*   Updated: 2021/11/21 03:00:21 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc) and returns a copy of 's1' with the chars
// specified in 'set' removed from the beginning and the end of the string.
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (s1)
	{
		if (!set)
			return ((char *)s1);
		end = ft_strlen(s1);
		if (end < 1)
			return (ft_strdup(""));
		start = 0;
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (start < end && ft_strchr(set, s1[end - 1]))
			end--;
		return (ft_substr(s1, start, end - start));
	}
	return (NULL);
}
