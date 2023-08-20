/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:41:11 by mpovill-          #+#    #+#             */
/*   Updated: 2023/08/20 14:56:48 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*ptr_s1;
	unsigned const char	*ptr_s2;

	ptr_s1 = s1;
	ptr_s2 = s2;
	i = 0;
	while (i < n && *ptr_s1 != '\0' && *ptr_s2 != '\0')
	{
		if (*ptr_s1 != *ptr_s2)
			return (*ptr_s1 - *ptr_s2);
		ptr_s1++;
		ptr_s2++;
		i++;
	}
	if (i != n)
		return (*ptr_s1 - *ptr_s2);
	return (0);
}
