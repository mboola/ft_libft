/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:51:10 by mpovill-          #+#    #+#             */
/*   Updated: 2023/08/20 14:55:40 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	search_needle_in_haystack(const char *haystack, const char *needle)
{
	while (*needle != '\0' && *haystack != '\0')
	{
		if (*needle != *haystack)
			return (0);
		needle++;
		haystack++;
	}
	if (*needle == '\0')
		return (1);
	return (-1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		result;
	size_t	count;

	if (*little == '\0')
		return ((char *)big);
	count = 0;
	while (count < len && *big != '\0')
	{
		if (*big == *little)
		{
			result = search_needle_in_haystack(big, little);
			if (result == 1)
				return ((char *)big);
			if (result == -1)
				return (NULL);
		}
		big++;
		count++;
	}
	return (NULL);
}
