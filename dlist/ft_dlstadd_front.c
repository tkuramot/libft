/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:15:02 by kura              #+#    #+#             */
/*   Updated: 2024/07/12 00:32:30 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlstadd_front(t_dlist **lst, t_dlist *node)
{
	if (!lst || !node)
		return ;
	if (*lst)
	{
		node->next = *lst;
		(*lst)->prev = node;
	}
	*lst = node;
}
