/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 04:25:26 by gpiccion          #+#    #+#             */
/*   Updated: 2021/11/18 04:25:26 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Converts the letter 'c' to upper case, if possible.
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= ' ';
	return (c);
}
