/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 04:10:23 by gpiccion          #+#    #+#             */
/*   Updated: 2021/11/18 04:10:23 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Converts the letter 'c' to lower case, if possible.
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += ' ';
	return (c);
}
