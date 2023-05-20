/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:28:39 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/21 03:34:20 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	result = ft_lstnew(f(lst->content));
	if (result == NULL)
		return (NULL);
	tmp = result;
	while (lst->next != NULL)
	{
		lst = lst->next;
		tmp->next = ft_lstnew(f(lst->content));
		if (tmp->next == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (result);
}
