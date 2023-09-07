/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:08:25 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/07 11:54:06 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_src;
	size_t	len_dst;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst > dstsize)
		return (len_src + dstsize);
	i = 0;
	j = len_dst;
	while (*(src + i) != '\0' && j < dstsize - 1)
	{
		*(dst + j) = *(src + i);
		i++;
		j++;
	}
	*(dst + j) = '\0';
	return (len_dst + len_src);
}
