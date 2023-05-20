/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:12:13 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/20 18:46:56 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	sz;

	sz = 0;
	if (lst == NULL)
		return (sz);
	while (lst != NULL)
	{
		lst = lst->next;
		sz++;
	}
	return (sz);
}
