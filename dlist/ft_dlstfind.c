/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 01:02:07 by kura              #+#    #+#             */
/*   Updated: 2024/07/26 01:03:55 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dsltfind(t_dlist *list, int (*find)(void *content))
{
	t_dlist	*tmp;

	tmp = list;
	while (tmp)
	{
		if (find(tmp->content))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
