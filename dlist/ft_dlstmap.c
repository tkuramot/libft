/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:51:58 by kura              #+#    #+#             */
/*   Updated: 2024/07/12 17:52:54 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dlstmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*new_lst;
	t_dlist	*tmp;

	if (!lst || !f)
		return (NULL);
	new_lst = ft_dlstnew(f(lst->content));
	if (!new_lst)
		return (NULL);
	tmp = new_lst;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_dlstnew(f(lst->content));
		if (!tmp->next)
		{
			ft_dlstclear(&new_lst, del);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new_lst);
}
