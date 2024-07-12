/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:50:39 by kura              #+#    #+#             */
/*   Updated: 2024/07/12 00:09:26 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

size_t	ft_dlstsize(t_dlist *lst)
{
	t_dlist	*node;
	size_t	size;

	node = lst;
	size = 0;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}
