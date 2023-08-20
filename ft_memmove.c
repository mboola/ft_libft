/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:14:47 by mpovill-          #+#    #+#             */
/*   Updated: 2023/08/20 13:43:14 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memmove(void *dest, const void *src, size_t n)
{
	size_t				count;
	unsigned char		*ptr_dest;

	ptr_dest = dest;
	if (dest > src)
	{
		count = n;
		while (count > 0)
		{
			count--;
			*(ptr_dest + count) = *(unsigned char *)(src + count);
		}
	}
	else
	{
		count = 0;
		while (count < n)
		{
			*(ptr_dest + count) = *(unsigned char *)(src + count);
			count++;
		}
	}
	return (dest);
}
