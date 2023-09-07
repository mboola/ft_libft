/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:48:04 by mpovill-          #+#    #+#             */
/*   Updated: 2023/08/23 12:57:06 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;

	i = 0;
	while (i < n && *(unsigned const char *)(s + i) != (unsigned char)c)
		i++;
	if (i < n && *(unsigned const char *)(s + i) == (unsigned char)c)
		return ((void *)(s + i));
	return (NULL);
}
