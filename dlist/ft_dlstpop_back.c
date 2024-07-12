/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpop_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 01:04:14 by kura              #+#    #+#             */
/*   Updated: 2024/07/12 01:04:24 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dlstpop_back(t_dlist **lst)
{
	t_dlist	*node;

	if (!lst || !*lst)
		return (NULL);
	node = *lst;
	while (node->next)
		node = node->next;
	if (node->prev)
		node->prev->next = NULL;
	else
		*lst = NULL;
	node->prev = NULL;
	return (node);
}
