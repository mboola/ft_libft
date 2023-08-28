/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:02:01 by mpovill-          #+#    #+#             */
/*   Updated: 2023/08/28 20:43:08 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*get_node(t_list *lst, void *(*f)(void *))
{
	void	*tmp;
	t_list	*node;

	tmp = (f)(lst->content);
	node = ft_lstnew(tmp);
	return (node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_to_return;
	t_list	*node;

	if (lst == NULL)
		return (NULL);
	lst_to_return = NULL;
	node = get_node(lst, f);
	while (lst->next != NULL && node != NULL)
	{
		ft_lstadd_back(&lst_to_return, node);
		lst = lst->next;
		node = get_node(lst, f);
	}
	if (node == NULL)
	{
		ft_lstclear(&lst_to_return, del);
		return (NULL);
	}
	ft_lstadd_back(&lst_to_return, node);
	return (lst_to_return);
}
