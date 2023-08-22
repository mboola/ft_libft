/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:16:15 by mpovill-          #+#    #+#             */
/*   Updated: 2023/08/22 20:16:52 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <time.h>

int	generate_rand_number(int min, int max)
{
	int range;
	int random;

	range = max - min + 1;
	random = rand() % range;
	return (random + min);
}

void	test_ft_isalpha(void)
{
	int	err;
	int	tmp;

	err = 0;
	tmp = -127;
	while (tmp < 127)
	{
		//printf("Value '%d' ft_isalpha: '%d' isalpha: '%d'\n", tmp, ft_isalpha(tmp), isalpha(tmp));
		if ((ft_isalpha(tmp) == 0 && isalpha(tmp) != 0) || ft_isalpha(tmp) != 0 && isalpha(tmp) == 0)
			err++;
		tmp++;
	}
	printf("ft_isalpha total errors: %d\n", err);
}

void	test_ft_isdigit(void)
{
	int	err;
	int	tmp;

	err = 0;
	tmp = -127;
	while (tmp < 256)
	{
		//printf("Value '%d' ft_isdigit: '%d' isdigit: '%d'\n", tmp, ft_isdigit(tmp), isdigit(tmp));
		if ((ft_isdigit(tmp) == 0 && isdigit(tmp) != 0) || (ft_isdigit(tmp) != 0 && isdigit(tmp) == 0))
			err++;
		tmp++;
	}
	printf("ft_isdigit total errors: %d\n", err);
}

void	test_ft_isalnum(void)
{
	int	err;
	int	tmp;

	err = 0;
	tmp = -127;
	while (tmp < 256)
	{
		//printf("Value '%d' ft_isalnum: '%d' isalnum: '%d'\n", tmp, ft_isalnum(tmp), isalnum(tmp));
		if ((ft_isalnum(tmp) == 0 && isalnum(tmp) != 0) || (ft_isalnum(tmp) != 0 && isalnum(tmp) == 0))
			err++;
		tmp++;
	}
	printf("ft_isalnum total errors: %d\n", err);
}

void	test_ft_isascii(void)
{
	int	err;
	int	tmp;

	err = 0;
	tmp = -127;
	while (tmp < 256)
	{
		//printf("Value '%d' ft_isascii: '%d' isascii: '%d'\n", tmp, ft_isascii(tmp), isascii(tmp));
		if ((ft_isascii(tmp) == 0 && isascii(tmp) != 0) || (ft_isascii(tmp) != 0 && isascii(tmp) == 0))
			err++;
		tmp++;
	}
	printf("ft_isascii total errors: %d\n", err);

}

void	test_ft_isprint(void)
{
	int	err;
	int	tmp;

	err = 0;
	tmp = -127;
	while (tmp < 256)
	{
		//intf("Value '%d' ft_isprint: '%d' isprint: '%d'\n", tmp, ft_isprint(tmp), isprint(tmp));
		if ((ft_isprint(tmp) == 0 && isprint(tmp) != 0) || (ft_isprint(tmp) != 0 && ft_isprint(tmp) == 0))
			err++;
		tmp++;
	}
	printf("ft_isprint total errors: %d\n", err);
}

void	test_ft_strlen(void)
{
	int	err;
	size_t	result;

	err = 0;
	if (ft_strlen("") != strlen(""))
		err++;
	if (ft_strlen("a") != strlen("a"))
		err++;
	if (ft_strlen("0123456789\n") != strlen("0123456789\n"))
		err++;
	printf("ft_strlen total errors: %d\n", err);
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
	printf("\n");
}

void	test_ft_memset(void)
{
	int	err;
	int	ptr_int1[10];
	int	ptr_int2[10];
	char	ptr_char1[60];
	char	ptr_char2[40];
	char	*ptr_char3;
	char	*ptr_char4;
	void	*ptr_void1;
	void	*ptr_void2;

	err = 0;
	ptr_void1 = ft_memset(ptr_int1, 'a', 8);
	ptr_void2 = memset(ptr_int2, 'a', 8);
	if (memcmp(ptr_void1, ptr_void2, 8))
		err++;

	ptr_void1 = ft_memset(ptr_char1, 'b', 10);
	ptr_void2 = memset(ptr_char2, 'b', 10);
	if (memcmp(ptr_void1, ptr_void2, 10))
		err++;

	bzero(ptr_char1, 60);
	ptr_char3 = &ptr_char1[10];
	ptr_void1 = ft_memset(ptr_char3, '1', 10);
	ptr_char4 = &ptr_char1[40];
	ptr_void2 = memset(ptr_char4, '1', 10);
	if (memcmp(ptr_void1 - 10, ptr_void2 - 10, 30))
		err++;
	printf("ft_memset total errors: %d\n", err);
}

void	test_ft_bzero(void)
{
	int	err;
	char	ptr[100];
	void	*ptr_void1;
	void	*ptr_void2;
	void	*ptr_void3;

	err = 0;
	ptr_void1 = memset(ptr, 'c', 100);
	ptr_void2 = ptr_void1 + 10;
	ft_bzero(ptr_void2, 10);
	ptr_void3 = ptr_void2 + 30;
	bzero(ptr_void3, 10);
	if (memcmp(ptr_void1, ptr_void3 - 10, 30))
		err++;
	printf("ft_bzero total errors: %d\n", err);
}

void	test_ft_memcpy(void)
{
	int	err;
	int	num;
	int	x;
	char	ptr[1000];
	void	*ptr_void1;
	void	*ptr_void2;
	void	*ptr_void3;
	void	*ptr_void4;

	err = 0;
	bzero(ptr, 1000);
	ptr_void1 = &ptr[10];
	ptr_void1 = memset(ptr_void1, 'a', 10);
	ptr_void2 = &ptr[40];
	ptr_void3 = ft_memcpy(ptr_void2, ptr_void1, 10);
	if (memcmp(ptr_void1 - 10, ptr_void2 - 10, 30))
		err++;
	if (memcmp(ptr_void3, ptr_void2, 10))
		err++;

	bzero(ptr, 1000);
	ptr_void1 = &ptr[10];
	ptr_void1 = memset(ptr_void1, 'a', 30);
	ptr_void2 = &ptr[60];
	ptr_void2 = memset(ptr_void2, 'b', 30);
	ptr_void1 += 10;
	ptr_void1 = memset(ptr_void1, 'c', 10);
	ptr_void2 += 10;
	ptr_void2 = memset(ptr_void2, 'c', 10);
	ptr_void3 = &ptr[100];
	ptr_void4 = &ptr[0];
	ptr_void4 = memcpy(ptr_void3, ptr_void4, 50);
	ptr_void3 = ft_memcpy(ptr_void1, ptr_void2, 10);
	if (memcmp(ptr_void4, ptr_void3 - 20, 50))
		err++;

	bzero(ptr, 1000);
	ptr_void1 = &ptr[0];
	num = 0;
	while (num < 60)
	{
		x = generate_rand_number(32, 80);
		ptr_void2 = memset(ptr_void1, x, 1);
		ptr_void1++;
		num++;
	}
	ptr_void1 = &ptr[0];
	ptr_void2 = &ptr[100];
	ptr_void2 = memcpy(ptr_void2, ptr_void1, 60);
	ptr_void4 = memcpy(ptr_void2 + 10, ptr_void2 + 20, 30);
	ptr_void3 = ft_memcpy(ptr_void1 + 10, ptr_void1 + 20, 30);
	if (memcmp(ptr_void1, ptr_void2, 60))
		err++;

	bzero(ptr, 1000);
	ptr_void1 = &ptr[0];
	num = 0;
	while (num < 60)
	{
		x = generate_rand_number(32, 80);
		ptr_void2 = memset(ptr_void1, x, 1);
		ptr_void1++;
		num++;
	}
	ptr_void1 = &ptr[0];
	ptr_void2 = &ptr[100];
	ptr_void2 = memcpy(ptr_void2, ptr_void1, 60);
	ptr_void4 = memcpy(ptr_void2 + 20, ptr_void2 + 10, 30);
	ptr_void3 = ft_memcpy(ptr_void1 + 20, ptr_void1 + 10, 30);
	if (memcmp(ptr_void4, ptr_void3, 30))
		err++;
	if (memcmp(ptr_void1, ptr_void2, 60))
		err++;

	printf("ft_memcpy total errors: %d\n", err);
}

void	test_ft_memmove(void)
{
	int	err;

	err = 0;
	printf("ft_memmove total errors: %d\n", err);
}

void	test_ft_toupper(void)
{
	int	err;
	int	tmp;

	err = 0;
	tmp = 0;
	while (tmp < 256)
	{
		//printf("Value '%d' ft_toupper: '%d' toupper: '%d'\n", tmp, ft_toupper(tmp), toupper(tmp));
		if (ft_toupper(tmp) != toupper(tmp))
			err++;
		tmp++;
	}
	printf("ft_toupper total errors: %d\n", err);
}

void	test_ft_tolower(void)
{
	int	err;
	int	tmp;

	err = 0;
	tmp = 0;
	while (tmp < 256)
	{
		//printf("Value '%d' ft_tolower: '%d' tolower: '%d'\n", tmp, ft_tolower(tmp), tolower(tmp));
		if (ft_tolower(tmp) != tolower(tmp))
			err++;
		tmp++;
	}
	printf("ft_tolower total errors: %d\n", err);
}

void	test_ft_strchr(void)
{
	int	err;
	char	*str;
	char	s[] = "abc123321cba";
	char	s2[] = "";

	err = 0;
	str = &s[0];
	if (ft_strchr(str, 'a') != strchr(str, 'a'))
		err++;
	if (ft_strchr(str, '4') != strchr(str, '4'))
		err++;
	str = &s2[0];
	if (ft_strchr(str, '\0') != strchr(str, '\0'))
		err++;
	printf("ft_strchr total errors: %d\n", err);
}

void	test_ft_strrchr(void)
{
	int	err;
	char	*str;
	char	s[] = "abc123321cba";
	char	s2[] = "";

	err = 0;
	str = &s[0];
	if (ft_strrchr(str, 'a') != strrchr(str, 'a'))
		err++;
	if (ft_strrchr(str, '4') != strrchr(str, '4'))
		err++;
	str = &s2[0];
	if (ft_strrchr(str, '\0') != strrchr(str, '\0'))
		err++;
	printf("ft_strrchr total errors: %d\n", err);
}

void	test_ft_strncmp(void)
{
	int	err;
	char	*str;
	char	*str2;
	char	s[] = "abc123";
	char	s1[] = "abc412";
	char	s2[] = "";

	err = 0;
	str = &s[0];
	str2 = &s1[0];
	if (ft_strncmp(str, str2, 0) != strncmp(str, str2, 0))
		err++;
	if (ft_strncmp(str, str2, 3) != strncmp(str, str2, 3))
		err++;
	if (ft_strncmp(str, str2, 5) != strncmp(str, str2, 5))
		err++;
	str = &s2[0];
	if (ft_strncmp(str, str2, 0) != strncmp(str, str2, 0))
		err++;
	if (ft_strncmp(str, str2, 3) != strncmp(str, str2, 3))
		err++;
	printf("ft_strncmp total errors: %d\n", err);
}

int	main(void)
{
	srand(time(NULL));
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
	
	test_ft_toupper();
	test_ft_tolower();
	test_ft_strchr();
	test_ft_strrchr();
	test_ft_strncmp();
	return (0);
}
