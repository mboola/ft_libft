/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:16:15 by mpovill-          #+#    #+#             */
/*   Updated: 2023/08/22 02:02:19 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	test_ft_isalpha(void)
{
	int	err;
	int	tmp;
	int	result;

	err = 0;
	tmp = -127;
	while (tmp < 127)
	{
		result = ft_isalpha(tmp);
		if ((tmp >= 'a' && tmp <= 'z') || (tmp >= 'A' && tmp <= 'Z'))
		{
			if (result != 1)
				err++;
		}
		else
		{
			if (result != 0)
				err++;
		}
		tmp++;
	}
	printf("ft_isalpha total errors: %d\n", err);
}

void	test_ft_isdigit(void)
{
	int	err;
	int	tmp;
	int	result;

	err = 0;
	tmp = -127;
	while (tmp < 256)
	{
		result = ft_isdigit(tmp);
		if (tmp >= '0' && tmp <= '9')
		{
			if (result != 1)
				err++;
		}
		else
		{
			if (result != 0)
				err++;
		}
		tmp++;
	}
	printf("ft_isdigit total errors: %d\n", err);
}

void	test_ft_isalnum(void)
{
	int	err;
	int	tmp;
	int	result;

	err = 0;
	tmp = -127;
	while (tmp < 256)
	{
		result = ft_isalnum(tmp);
		if ((tmp >= 'a' && tmp <= 'z') || (tmp >= 'A' && tmp <= 'Z') || (tmp >= '0' && tmp <= '9'))
		{
			if (result != 1)
				err++;
		}
		else
		{
			if (result != 0)
				err++;
		}
		tmp++;
	}
	printf("ft_isalnum total errors: %d\n", err);

}

void	test_ft_isascii(void)
{
	int	err;
	int	tmp;
	int	result;

	err = 0;
	tmp = -127;
	while (tmp < 256)
	{
		result = ft_isascii(tmp);
		if (tmp >= 0 && tmp <= 255)
		{
			if (result != 1)
				err++;
		}
		else
		{
			if (result != 0)
				err++;
		}
		tmp++;
	}
	printf("ft_isascii total errors: %d\n", err);

}

void	test_ft_isprint(void)
{
	int	err;
	int	tmp;
	int	result;

	err = 0;
	tmp = -127;
	while (tmp < 256)
	{
		result = ft_isprint(tmp);
		if (tmp >= 32 && tmp <= 126)
		{
			if (result != 1)
				err++;
		}
		else
		{
			if (result != 0)
				err++;
		}
		tmp++;
	}
	printf("ft_isprint total errors: %d\n", err);
}

void	test_ft_strlen(void)
{
	int	err;
	size_t	result;

	err = 0;
	if (ft_strlen("") != 0)
		err++;
	if (ft_strlen("a") != 1)
		err++;
	if (ft_strlen("0123456789") != 10)
		err++;
	printf("ft_strlen total errors: %d\n", err);
}

int	main(void)
{
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_strlen();
	return (0);
}
