/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:01:05 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/13 11:01:25 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*cleanup(const char *str, char *n)
{
	while (*str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v' || *str == ' ')
		str++;
	*n = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*n *= -1;
		str++;
	}
	while (*str == '0')
		str++;
	return ((char *)str);
}

int	ft_atoi_err(const char *str, char *err)
{
	unsigned int	num;
	unsigned int	min;
	char			n;

	str = cleanup(str, &n);
	num = 0;
	min = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if (num > min)
			min = num;
		else
		{
			*err = 1;
			return (0);
		}
		str++;
	}
	if ((num - 1 > MAX_INT && n == -1) || (num > MAX_INT) || *str != '\0')
		*err = 1;
	return (num * n);
}

int	ft_atoi(const char *str)
{
	int		num;
	char	n;

	str = cleanup(str, &n);
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	num *= n;
	return (num);
}
