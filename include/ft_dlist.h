/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:38:12 by tkuramot          #+#    #+#             */
/*   Updated: 2024/07/26 01:28:59 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLIST_H
# define FT_DLIST_H

# include <stddef.h>

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

t_dlist				*ft_dlstnew(void *content);
size_t				ft_dlstsize(t_dlist *lst);
t_dlist				*ft_dlstlast(t_dlist *lst);
void				ft_dlstadd_front(t_dlist **lst, t_dlist *node);
void				ft_dlstadd_back(t_dlist **lst, t_dlist *node);
t_dlist				*ft_dlstfind(t_dlist *list, void *expected,
						int (*find)(void *actual, void *expected));
t_dlist				*ft_dlstpop_front(t_dlist **lst);
t_dlist				*ft_dlstpop_middle(t_dlist *lst);
t_dlist				*ft_dlstpop_back(t_dlist **lst);
void				ft_dlstdelone(t_dlist *lst, void (*del)(void *));
void				ft_dlstclear(t_dlist **lst, void (*del)(void *));
void				ft_dlstiter(t_dlist *lst, void (*f)(void *));
t_dlist				*ft_dlstmap(t_dlist *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
