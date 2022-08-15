/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:23:40 by gpiccion          #+#    #+#             */
/*   Updated: 2021/11/18 12:23:40 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns a pointer to the first occurrence of the char 'c' in 'str'.
// If no match is found, returns NULL.
char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && (char)str[i] != (char)c)
		i++;
	if ((char)str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}
