/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:57:37 by gpiccion          #+#    #+#             */
/*   Updated: 2021/11/18 00:57:37 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Sets the first 'n' bytes of the area starting at 's' to zero.
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
