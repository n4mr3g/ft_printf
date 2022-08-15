/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:02:55 by gpiccion          #+#    #+#             */
/*   Updated: 2022/03/20 19:18:59 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Counts the number of elements in the list 'lst'.
int	ft_lstsize(t_list *lst)
{
	t_list	*aux;
	int		i;

	if (!lst)
		return (0);
	i = 1;
	aux = lst;
	while (aux->next)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}
