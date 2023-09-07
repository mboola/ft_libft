/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 02:01:29 by mpovill-          #+#    #+#             */
/*   Updated: 2023/08/24 13:03:02 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	size_t	str_len;

	s_len = ft_strlen(s);
	if (s_len < start)
		str_len = 1;
	else
	{
		if ((s_len - start + 1) > len)
			str_len = (s_len - start + 1) * (len > 0) + 1;
		else
			str_len = len * (s_len > 0) + 1;
	}
	str = malloc(sizeof(char) * str_len);
	if (str == NULL)
		return (NULL);
	if (str_len == 1)
		*str = '\0';
	else
		ft_strlcpy(str, s + start, str_len);
	return (str);
}
