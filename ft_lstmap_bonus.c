/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:28:39 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/20 14:02:51 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	ret = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst != NULL)
	{
		ft_lstadd_back(&ret, ft_lstnew(f(lst->content)));
		if (del != NULL)
		{
			tmp = lst;
			lst = lst->next;
			ft_lstdelone(tmp, del);
		}
		else
			lst = lst->next;
	}
	return (ret);
}
