/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpop_middle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:48:23 by kura              #+#    #+#             */
/*   Updated: 2024/08/03 16:16:46 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dlstpop_middle(t_dlist **lst)
{
	t_dlist	*cur;
	t_dlist	*next;

	if (!lst || !*lst)
		return (NULL);
	cur = *lst;
	next = cur->next;
	if (next)
	{
		next->prev = cur->prev;
		cur->prev->next = next;
		*lst = next;
	}
	else
		*lst = cur->prev;
	cur->next = NULL;
	cur->prev = NULL;
	return (cur);
}
