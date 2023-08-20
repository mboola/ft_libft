/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:24:46 by mpovill-          #+#    #+#             */
/*   Updated: 2023/08/20 14:38:17 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (*src != '\0' && i < size - 1)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	while (i < size - 1)
	{
		*dst = '\0';
		i++;
	}
	*dst = '\0';
	return (i);
}
