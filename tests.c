/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:16:15 by mpovill-          #+#    #+#             */
/*   Updated: 2023/08/24 02:07:36 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <time.h>

char	*strnstr(const char *s, const char *find, size_t slen)
{
	char c, sc;
	size_t len;

	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if (slen-- < 1 || (sc = *s++) == '\0')
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}

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

void	test_ft_strlcpy(void)
{
	int	err;

	err = 0;
	printf("ft_strlcpy total errors: %d\n", err);
}

void	test_ft_strlcat(void)
{
	int	err;

	err = 0;
	printf("ft_strlcat total errors: %d\n", err);
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

void	test_ft_memchr(void)
{
	int	err;
	int	len;
	void	*ptr;
	char	s[] = "abc123321cba";
	char	s2[] = "\0";
	char	s3[] = "1\0";
	len = strlen(s);
	err = 0;
	ptr = &s[0];
	if (ft_memchr(ptr, 'a', len) != memchr(ptr, 'a', len))
		err++;
	if (ft_memchr(ptr, '4', len) != memchr(ptr, '4', len))
		err++;
	ptr = &s2[0];
	len = strlen(s2);
	if (ft_memchr(ptr, '\0', len) != memchr(ptr, '\0', len))
		err++;
	if (ft_memchr(ptr, '\0', 1) != memchr(ptr, '\0', 1))
		err++;
	ptr = &s3[0];
	len = strlen(s3);
	if (ft_memchr(ptr, '\0', len) != memchr(ptr, '\0', len))
		err++;
	if (ft_memchr(ptr, '\0', 2) != memchr(ptr, '\0', 2))
		err++;
	
	printf("ft_memchr total errors: %d\n", err);
}

void	test_ft_memcmp(void)
{
	int	err;
	void	*ptr1;
	void	*ptr2;
	char	s1[] = "abc123";
	char	s2[] = "abc412";
	char	s3[] = "";

	err = 0;
	ptr1 = &s1[0];
	ptr2 = &s2[0];
	if (ft_memcmp(ptr1, ptr2, 0) != memcmp(ptr1, ptr2, 0))
		err++;
	if (ft_memcmp(ptr1, ptr2, 3) != memcmp(ptr1, ptr2, 3))
		err++;
	if (ft_memcmp(ptr1, ptr2, 5) != memcmp(ptr1, ptr2, 5))
		err++;
	ptr1 = &s3[0];
	if (ft_memcmp(ptr1, ptr2, 0) != memcmp(ptr1, ptr2, 0))
		err++;
	if (ft_memcmp(ptr1, ptr2, 3) != memcmp(ptr1, ptr2, 3))
		err++;
	printf("ft_memcmp total errors: %d\n", err);
}

void	test_ft_strnstr(void)
{
	int	err;
	char	empty_haystack[] = "\0";
	char	empty_needle[] = "\0";
	char	easy_haystack[] = "abc";
	char	easy_needle[] = "ab";
	char	medium_haystack[] = "acabbcabbbcc";
	char	medium_needle1[] = "abb";
	char	medium_needle2[] = "bcc";
	char	hard_haystack[] = "aabaabbacaabbaabbaabcaabbaabc";
	char	hard_needle[] = "aabbaabc";

	err = 0;
	if (ft_strnstr(empty_haystack, empty_needle, strlen(empty_haystack)) != strnstr(empty_haystack, empty_needle, strlen(empty_haystack)))
		err++;
	if (ft_strnstr(empty_haystack, easy_needle, strlen(empty_haystack)) != strnstr(empty_haystack, easy_needle, strlen(empty_haystack)))
		err++;
	if (ft_strnstr(easy_haystack, empty_needle, strlen(easy_haystack)) != strnstr(easy_haystack, empty_needle, strlen(easy_haystack)))
		err++;
	if (ft_strnstr(easy_haystack, easy_needle, 3) != strnstr(easy_haystack, easy_needle, 3))
		err++;
	if (ft_strnstr(easy_haystack, easy_needle, 1) != strnstr(easy_haystack, easy_needle, 1))
		err++;
	if (ft_strnstr(medium_haystack, medium_needle1, strlen(medium_haystack)) != strnstr(medium_haystack, medium_needle1, strlen(medium_haystack)))
		err++;
	if (ft_strnstr(medium_haystack, medium_needle1, 4) != strnstr(medium_haystack, medium_needle1, 4))
		err++;
	if (ft_strnstr(medium_haystack, medium_needle2, strlen(medium_haystack)) != strnstr(medium_haystack, medium_needle2, strlen(medium_haystack)))
		err++;
	if (ft_strnstr(medium_haystack, medium_needle2, strlen(medium_haystack) - 1) != strnstr(medium_haystack, medium_needle2, strlen(medium_haystack) - 1))
		err++;
	if (ft_strnstr(hard_haystack, hard_needle, strlen(hard_haystack)) != strnstr(hard_haystack, hard_needle, strlen(hard_haystack)))
		err++;
	if (ft_strnstr(hard_haystack, hard_needle, 20) != strnstr(hard_haystack, hard_needle, 20))
		err++;
	printf("ft_strnstr total errors: %d\n", err);
}

void	test_ft_atoi(void)
{
	int	err;

	err = 0;
	if (ft_atoi("") != atoi(""))
		err++;
	if (ft_atoi("1") != atoi("1"))
		err++;
	if (ft_atoi("-1") != atoi("-1"))
		err++;
	if (ft_atoi("0") != atoi("0"))
		err++;
	if (ft_atoi("2147483647") != atoi("2147483647"))
		err++;
	if (ft_atoi("00000002147483647") != atoi("00000002147483647"))
		err++;
	if (ft_atoi("-2147483648") != atoi("-2147483648"))
		err++;
	if (ft_atoi("-00002147483648") != atoi("-00002147483648"))
		err++;
	if (ft_atoi("\n\t -123") != atoi("\n\t -123"))
		err++;
	if (ft_atoi(" +123") != atoi(" +123"))
		err++;
	if (ft_atoi("-+123") != atoi("-+123"))
		err++;
	printf("ft_atoi total errors: %d\n", err);
}

void	test_ft_calloc(void)
{
	int	err;

	err = 0;
	printf("ft_calloc total errors: %d\n", err);
}

void	test_ft_strdup(void)
{
	int	err;

	err = 0;
	printf("ft_strdup total errors: %d\n", err);
}

void	test_ft_substr(void)
{
	int	err;

	err = 0;
	printf("ft_substr total errors: %d\n", err);
}

void	test_ft_strjoin(void)
{
	int	err;

	err = 0;
	printf("ft_strjoin total errors: %d\n", err);
}

void	test_ft_strtrim(void)
{
	int	err;

	err = 0;
	printf("ft_strtrim total errors: %d\n", err);
}

void	test_ft_split(void)
{
	int	err;

	err = 0;
	printf("ft_split total errors: %d\n", err);
}

void	test_ft_itoa(void)
{
	int	err;
	int	num;

	err = 0;
//	printf("%s\n", ft_itoa(0));
	if (strncmp(ft_itoa(0), "0", 2))
		err++;
//	printf("%s\n", ft_itoa(-1));
	if (strncmp(ft_itoa(-1), "-1", 3))
		err++;
//	printf("%s\n", ft_itoa(2147483647));
	if (strncmp(ft_itoa(2147483647), "2147483647", 11))
		err++;
//	printf("%s\n", ft_itoa(-2147483648));
	if (strncmp(ft_itoa(-2147483648), "-2147483648", 12))
		err++;
	printf("ft_itoa total errors: %d\n", err);
}

void	test_ft_strmapi(void)
{
	int	err;

	err = 0;
	printf("ft_strmapi total errors: %d\n", err);
}

void	test_ft_striteri(void)
{
	int	err;

	err = 0;
	printf("ft_striteri total errors: %d\n", err);
}

void	test_ft_putchar_fd(void)
{
	int	err;

	err = 0;
	printf("ft_putchar_fd total errors: %d\n", err);
}

void	test_ft_putstr_fd(void)
{
	int	err;

	err = 0;
	printf("ft_putstr_fd total errors: %d\n", err);
}

void	test_ft_putendl_fd(void)
{
	int	err;

	err = 0;
	printf("ft_putendl_fd total errors: %d\n", err);
}

void	test_ft_putnbr_fd(void)
{
	int	err;

	err = 0;
	printf("ft_putnbr_fd total errors: %d\n", err);
}

int	main(void)
{
	srand(time(NULL));
	test_ft_isalpha();	//done && tested
	test_ft_isdigit();	//done && tested
	test_ft_isalnum();	//done && tested
	test_ft_isascii();	//done && tested
	test_ft_isprint();	//done && tested
	test_ft_strlen();	//done && tested
	test_ft_memset();	//done && tested
	test_ft_bzero();	//done && tested
	test_ft_memcpy();	//done && tested
	test_ft_memmove();	//done
	test_ft_strlcpy();	//done
	test_ft_strlcat();	//done
	test_ft_toupper();	//done && tested
	test_ft_tolower();	//done && tested
	test_ft_strchr();	//done && tested
	test_ft_strrchr();	//done && tested
	test_ft_strncmp();	//done && tested
	test_ft_memchr();	//done && tested
	test_ft_memcmp();	//done && tested
	test_ft_strnstr();	//done && tested
	test_ft_atoi();		//done && tested
	test_ft_calloc();	//done
	test_ft_strdup();	//done
	test_ft_substr();	//done
	test_ft_strjoin();	//done
	test_ft_strtrim();
	test_ft_split();	//done
	test_ft_itoa();		//done && tested
	test_ft_strmapi();
	test_ft_striteri();
	test_ft_putchar_fd();
	test_ft_putstr_fd();
	test_ft_putendl_fd();
	test_ft_putnbr_fd();
	return (0);
}
