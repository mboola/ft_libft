/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:08:25 by mpovill-          #+#    #+#             */
/*   Updated: 2023/08/20 14:38:53 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(dst) + ft_strlen(src));
	i = 0;
	while (*dst != '\0' && i < size - 1)
	{
		i++;
		dst++;
	}
	while (*src != '\0' && i < size - 1)
	{
		i++;
		*dst = *src;
		dst++;
		src++;
	}
	while (i < size - 1)
	{
		*dst = '\0';
		i++;
	}
	*dst = '\0';
	return (i);
}
