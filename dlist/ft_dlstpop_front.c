/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpop_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:53:11 by kura              #+#    #+#             */
/*   Updated: 2024/07/12 00:57:23 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dlstpop_front(t_dlist **lst)
{
	t_dlist	*node;

	if (!lst || !*lst)
		return (NULL);
	node = *lst;
	*lst = node->next;
	if (*lst)
		(*lst)->prev = NULL;
	node->next = NULL;
	return (node);
}
