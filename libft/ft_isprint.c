/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:36:22 by gpiccion          #+#    #+#             */
/*   Updated: 2021/11/17 23:36:22 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns 1 if 'c' is a printable character, otherwise returns 0.
int	ft_isprint(char c)
{
	return (c >= ' ' && c <= '~');
}
