/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:04:09 by mpovill-          #+#    #+#             */
/*   Updated: 2023/08/18 16:26:59 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memset(void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*ptr;

	ptr = s;
	count = 0;
	while (count < n)
	{
		*(ptr + count) = (unsigned char)c;
		count++;
	}
	return (s);
}
