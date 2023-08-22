/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:16:15 by mpovill-          #+#    #+#             */
/*   Updated: 2023/08/22 13:00:00 by mpovill-         ###   ########.fr       */
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

int	aux_memcmp(void *s1, void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(char *)s1 != *(char *)s2)
			return (0);
		s1++;
		s2++;
		i++;
	}
	return (1);
}

void	aux_memprint(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		printf("%u", *(unsigned char *)s);
		s++;
		i++;
	}
	printf("	");
}

void	test_ft_memset(void)
{
	int	err;
	int	ptr_int[8];
	char	ptr_char[10];
	void	*ptr_void;

	err = 0;
	ptr_void = ft_memset(ptr_int, 'a', 8);
	if (!aux_memcmp(ptr_void, "aaaaaaaa", 8))
		err++;
	//aux_memprint(ptr_void, 8);
	ptr_void = ft_memset(ptr_char, 'b', 4);
	if (!aux_memcmp(ptr_void, "bbbb", 4))
		err++;
	//aux_memprint(ptr_void, 4);
	ptr_void = ft_memset(ptr_char, 97, 10);
	if (!aux_memcmp(ptr_void, "aaaaaaaaaa", 10))
		err++;
	//aux_memprint(ptr_void, 10);
	ptr_void = ft_memset(ptr_int, '1', 1);
	if (!aux_memcmp(ptr_void, "1", 1))
		err++;
	printf("ft_memset total errors: %d\n", err);
}

void	test_ft_bzero(void)
{
	int	err;
	int	ptr_int[100];
	void	*ptr_void;

	err = 0;
	ptr_void = ft_memset(ptr_int, 'a', 4);
	//aux_memprint(ptr_void, 4);
	ft_bzero(ptr_void, 8);
	//aux_memprint(ptr_void, 8);
	if (!aux_memcmp(ptr_void, "\0\0\0\0\0\0\0\0", 8))
		err++;
	printf("ft_bzero total errors: %d\n", err);
}

void	test_ft_memcpy(void)
{
	int	err;
	char	ptr[100];
	char	ptr_char[100];
	void	*ptr_test2;
	void	*ptr_test;
	void	*ptr_void;

	err = 0;
	ft_bzero(ptr, 100);
	ft_bzero(ptr_char, 100);
	ptr_void = &ptr[2];
	ptr_test = ft_memset(ptr, 'a', 8);
	//aux_memprint(ptr_test, 10);
	ptr_test2 = ft_memset(ptr_char, 'b', 8);
	//aux_memprint(ptr_test2, 10);
	ptr_void = ft_memcpy(ptr_void, ptr_test2, 8);
	if (!aux_memcmp(ptr_void, "bbbbbbbb", 8))
		err++;
	//aux_memprint(ptr_test, 20);
	printf("ft_memcpy total errors: %d\n", err);
}

void	test_ft_memmove(void)
{
	int	err;

	err = 0;
	printf("ft_memmove total errors: %d\n", err);
}

int	main(void)
{
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_strlen();
	test_ft_memset();
	test_ft_bzero();
	test_ft_memcpy();
	test_ft_memmove();
	return (0);
}
