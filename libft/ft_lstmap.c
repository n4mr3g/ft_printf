/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:59:32 by gpiccion          #+#    #+#             */
/*   Updated: 2022/03/20 22:53:13 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterates the list 'lst' and applies the function 'f' to the
// content of each element, creating a new list as a result.
// The 'del' function is used to delete the content of an element if needed.
// Returns a pointer to the new list, or NULL if the allocation fails.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*lst2_first;

	if (!f || !lst)
		return (NULL);
	lst2_first = ft_lstnew((*f)(lst->content));
	if (!lst2_first)
		return (NULL);
	new = lst2_first;
	lst = lst->next;
	while (lst)
	{
		new->next = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(&lst2_first, del);
			return (NULL);
		}
		lst = lst->next;
		new = new->next;
	}
	return (lst2_first);
}
