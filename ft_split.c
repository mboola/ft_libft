/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 00:38:53 by mpovill-          #+#    #+#             */
/*   Updated: 2023/08/24 01:09:33 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_strings(const char *str, char c)
{
	int	n_strs;
	int	n_chars;

	n_chars = 0;
	n_strs = 0;
	while (*str != '\0')
	{
		if (*str == c)
		{
			if (n_chars != 0)
			{
				n_chars = 0;
				n_strs++;
			}
			str++;
		}
		else
		{
			n_chars++;
			str++;
		}
	}
	if (n_chars != 0)
		n_strs++;
	return (n_strs);
}

void	trnfrm_str_to_mat(const char *str, char c, int length, char **matrix)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (i < length && *(str + word) != '\0')
	{
		if (*str == c)
		{
			if (word != 0)
			{
				ft_strlcpy(matrix[i], str, word);
				i++;
				str = str + word;
				word = 0;
			}
			str++;
		}
		else
			word++;
	}
	if (word != 0)
		ft_strlcpy(matrix[i], str, word);
}

char	**ft_split(char const *s, char c)
{
	int		length;
	char	**matrix;

	length = count_strings(s, c);
	if (length == 0)
		return (NULL);
	matrix = malloc(sizeof(char *) * (length + 1));
	if (matrix == NULL)
		return (NULL);
	trnfrm_str_to_mat(s, c, length, matrix);
	matrix[length] = NULL;
	return (matrix);
}
