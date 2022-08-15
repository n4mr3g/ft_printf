/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:53:32 by gpiccion          #+#    #+#             */
/*   Updated: 2021/11/18 20:53:32 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc) and returns a substring from the string 's'. 
// The substring begins at index 'start' and is of maximum size 'len'.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;
	size_t	str_length;

	str_length = ft_strlen(s);
	if (str_length < start + len)
	{
		if (str_length < start)
			start = str_length;
		else
			len = str_length - start;
	}
	i = 0;
	while (s[i + start] && len-- > 0)
		i++;
	out = malloc(i + 1);
	if (!out)
		return (NULL);
	ft_strlcpy(out, s + start, i + 1);
	return (out);
}
