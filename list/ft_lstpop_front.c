/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 00:40:07 by tkuramot          #+#    #+#             */
/*   Updated: 2023/09/20 00:42:57 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstpop_front(t_list **lst)
{
	t_list	*front;

	if (!lst || !*lst)
		return (NULL);
	front = *lst;
	*lst = (*lst)->next;
	return (front);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list *lst = NULL;
	printf("%p\n", ft_lstpop_front(&lst));
	lst = ft_lstnew("aa");
	ft_lstadd_back(&lst, ft_lstnew("bb"));
	ft_lstadd_back(&lst, ft_lstnew("cc"));
	ft_lstadd_back(&lst, ft_lstnew("dd"));
	printf("%s\n", (char *)ft_lstpop_front(&lst)->content);
	printf("===\n");
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}
*/
