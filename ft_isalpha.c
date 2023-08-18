/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:10:18 by mpovill-          #+#    #+#             */
/*   Updated: 2023/08/18 15:18:01 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

static int	islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if (isupper(c) || islower(c))
		return (1);
	return (0);
}
