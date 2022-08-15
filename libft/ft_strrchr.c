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

// Returns a pointer to the last occurrence of the char 'c' in the string 's'.
char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*aux;

	i = ft_strlen(str);
	aux = (char *) str;
	while (i >= 0)
	{
		if (aux[i] == (char)c)
			return (aux + i);
		i--;
	}
	return (NULL);
}
