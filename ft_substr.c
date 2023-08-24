/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 02:01:29 by mpovill-          #+#    #+#             */
/*   Updated: 2023/08/21 02:28:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	count;

	if (len + 1 > INT_MAX)
		return (NULL);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	count = 0;
	while (count < start && *(s + count) != '\0')
		count++;
	if (*(s + count) == '\0')
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(str, s, len + 1);
	return (str);
}
