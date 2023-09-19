/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 00:27:55 by tkuramot          #+#    #+#             */
/*   Updated: 2023/09/20 00:39:29 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstpop_back(t_list **lst)
{
	t_list	*node;
	t_list	*last;

	if (!lst)
		return (NULL);
	last = ft_lstlast(*lst);
	if (!last)
		return (NULL);
	if (*lst == last)
	{
		*lst = NULL;
		return (last);
	}
	node = *lst;
	while (node->next != last)
		node = node->next;
	node->next = NULL;
	return (last);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list *lst = NULL;
	printf("%p\n", ft_lstpop_back(&lst));
	lst = ft_lstnew("aa");
	ft_lstadd_back(&lst, ft_lstnew("bb"));
	ft_lstadd_back(&lst, ft_lstnew("cc"));
	ft_lstadd_back(&lst, ft_lstnew("dd"));
	printf("%s\n", (char *)ft_lstpop_back(&lst)->content);
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}
*/
