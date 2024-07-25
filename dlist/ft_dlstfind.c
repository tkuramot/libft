/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 01:02:07 by kura              #+#    #+#             */
/*   Updated: 2024/07/26 01:28:47 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dlstfind(t_dlist *list, void *expected, int (*find)(void *actual,
			void *expected))
{
	t_dlist	*tmp;

	tmp = list;
	while (tmp)
	{
		if (find(tmp->content, expected))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
