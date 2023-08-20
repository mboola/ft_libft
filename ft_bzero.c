/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:07:12 by mpovill-          #+#    #+#             */
/*   Updated: 2023/08/20 13:45:36 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			count;
	unsigned char	*ptr;

	ptr = s;
	count = 0;
	while (count < n)
	{
		*(ptr + count) = '\0';
		count++;
	}
}
