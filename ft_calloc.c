/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:59:17 by mpovill-          #+#    #+#             */
/*   Updated: 2023/08/21 02:00:22 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cannot_mult(size_t nmemb, size_t size)
{
	if (nmemb > INT_MAX || size > INT_MAX)
		return (1);
	if (INT_MAX / nmemb < size)
		return (1);
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (cannot_mult(nmemb, size))
		return (NULL);
	ptr = malloc(size * nmemb);
	return (ptr);
}
