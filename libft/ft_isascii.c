/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:35:30 by gpiccion          #+#    #+#             */
/*   Updated: 2021/11/17 23:35:30 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns 1 if 'c' is a 7-bit unsigned char value
// that fits into the ASCII character set, otherwise returns 0.
int	ft_isascii(size_t c)
{
	return (c <= 127);
}
