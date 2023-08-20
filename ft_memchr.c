/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:48:04 by mpovill-          #+#    #+#             */
/*   Updated: 2023/08/20 14:56:06 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char	*ptr;

	ptr = s;
	i = 0;
	while (i < n && *(ptr + i) != '\0' && *(ptr + i) != c)
		i++;
	if (*(ptr + i) == c)
		return ((char *)(ptr + i));
	return (NULL);
}
