/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dolstextract_front.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:21:15 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/13 11:21:22 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dolist	*ft_dolstextract_front(t_dolist **lst)
{
	t_dolist	*first;

	first = *lst;
	*lst = (*lst)->next;
	if (*lst != NULL)
		(*lst)->previous = NULL;
	first->next = NULL;
	return (first);
}
