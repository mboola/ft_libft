/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:16:15 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/07 12:36:19 by mpovill-         ###   ########.fr       */
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
		if ((ft_isalpha(tmp) == 0 && isalpha(tmp) != 0) || (ft_isalpha(tmp) != 0 && isalpha(tmp) == 0))
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
	char	str1[] = "abcd";
	char	str2[5];
	char	str3[] ="0123456789";
	size_t	count;

	err = 0;
	count = ft_strlcpy(str2, str1, strlen(str1) + 1);
	if (count != strlen(str1))
		err++;
	if (strncmp(str2, str1, strlen(str1) + 1))
		err++;
	count = ft_strlcpy(str3, str1, strlen(str1) + 1);
	if (count != strlen(str1))
		err++;
	if (strncmp(str3, str1, strlen(str1) + 1))
		err++;
	if (strncmp(str3, "abcd\0\\56789", 11))
		err++;
	printf("ft_strlcpy total errors: %d\n", err);
}

void	test_ft_strlcat(void)
{
	int	err;
	char	str1[] = "abcd";
	char	str2[5] = "\0";
	char	str3[15] = "0123456789";
	char	*dest;
	size_t	count;
	size_t	len1;
	size_t	len2;

	err = 0;
	len1 = strlen(str1);
	len2 = strlen(str2);
	count = ft_strlcat(str2, str1, len2 + len1 + 1);
	if (count != len1 + len2)
		err++;
	if (strncmp(str2, "abcd", 5))
		err++;
	len2 = strlen(str3);
	count = ft_strlcat(str3, str1, len2 + len1 + 1);
	if (count != len1 + len2)
		err++;
	if (strncmp(str3, "0123456789abcd", 15))
		err++;
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
	printf("%d\n", ft_strncmp(str, str2, 0));
	printf("%d\n", strncmp(str, str2, 0));
	if (ft_strncmp(str, str2, 0) != strncmp(str, str2, 0))
		err++;

	str = &s2[0];
	str2 = &s1[0];

	if (ft_strncmp(str, str2, 3) != strncmp(str, str2, 3))
		err++;
	printf("%d\n", ft_strncmp(str2, str, 3));
	printf("%d\n", strncmp(str2, str, 3));
	if (ft_strncmp(str2, str, 3) != strncmp(str2, str, 3))
		err++;

	printf("%d\n", ft_strncmp("\20", "\0", 6));
	printf("%d\n", '\20');
	printf("%d\n", '\0');
	printf("%d\n", strncmp("\20", "\0", 6));

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
	if (strncmp(ft_substr("test1", 2, 1), "s", 2))
		err++;
	if (strncmp(ft_substr("test2", 2, 3), "st2", 4))
		err++;
	if (ft_substr("1", 3, 1) != NULL)
		err++;
	if (strncmp(ft_substr("0123", 0, 4), "0123", 5))
		err++;
	if (strncmp(ft_substr("0123", 3, 1), "3", 2))
		err++;
	if (strncmp(ft_substr("0123", 3, 2), "3\0\0", 3))
		err++;
	if (strncmp(ft_substr("01", 1, 100), "1", 100))
		err++;
	printf("ft_substr total errors: %d\n", err);
}

void	test_ft_strjoin(void)
{
	int	err;

	err = 0;
	if (strncmp(ft_strjoin("a", "b"), "ab", 3))
		err++;
	if (strncmp(ft_strjoin("ab", ""), "ab", 3))
		err++;
	if (strncmp(ft_strjoin("", "ab"), "ab", 3))
		err++;
	if (strncmp(ft_strjoin("", ""), "", 1))
		err++;
	if (strncmp(ft_strjoin("1234", "4321"), "12344321", 9))
		err++;
	if (strncmp(ft_strjoin("1234", ""), "1234", 5))
		err++;
	if (strncmp(ft_strjoin("", "4321"), "4321", 5))
		err++;
	if (strncmp(ft_strjoin("123", "4321"), "1234321", 8))
		err++;
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

char	test_ft_param1(unsigned int num, char c)
{
	return (c + num);
}

char	test_ft_param2(unsigned int num, char c)
{
	return (c);
}

char	test_ft_param3(unsigned int num, char c)
{
	if (num % 2 == 0)
		return ('0');
	return (c);
}

void	test_ft_strmapi(void)
{
	int	err;
	char	str[] = "abc";

	err = 0;
	if (ft_strmapi(str, test_ft_param1) == &str[0])
		err++;
	if (strncmp(ft_strmapi("abc", test_ft_param1), "ace", 4))
		err++;
	if (strncmp(ft_strmapi("", test_ft_param1), "", 1))
		err++;
	if (strncmp(ft_strmapi("abc", test_ft_param2), "abc", 4))
		err++;
	if (strncmp(ft_strmapi("abcdef", test_ft_param3), "0b0d0f", 7))
		err++;
	printf("ft_strmapi total errors: %d\n", err);
}

void	test_ft_param4(unsigned int num, char *c)
{
	*c = *c + num;
}

void	test_ft_striteri(void)
{
	int	err;
	char	str[] = "abc";
	char	str2[] = "";
	char	*ptr;
	char	*ptr2;

	ptr = &str[0];
	ptr2 = &str2[0];
	err = 0;
	ft_striteri(ptr, test_ft_param4);
	if (strncmp(ptr, "ace", 4))
		err++;
	ft_striteri(ptr2, test_ft_param4);
	if (strncmp(ptr2, "", 1))
		err++;
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

int	test_ft_lstnew_bonus(void)
{
	int	err;
	t_list	*list;

	err = 0;
	list = ft_lstnew(&err);
	if (list->content != &err)
		err++;
	if (list->next != NULL)
		err++;
	printf("ft_lstnew_bonus total errors: %d\n", err);
	return (err);
}

int	test_ft_lstadd_front(void)
{
	int	err;
	int	value1;
	int	value2;
	int	value3;
	t_list	*list;
	t_list	**list2;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	err = 0;
	list2 = NULL;
	node1 = NULL;
	ft_lstadd_front(list2, node1);
	if (list2 != NULL)
		err++;

	list = NULL;
	ft_lstadd_front(&list, node1);
	if (list != NULL)
		err++;

	list = node1;
	node2 = ft_lstnew(&value2);
//	printf("%p\n", node2);
	ft_lstadd_front(&list, node2);
	if (list != node2)
		err++;
	if (list->next != NULL)
		err++;

	node1 = ft_lstnew(&value1);
	list = node1;
//	printf("%p\n", node1);
	ft_lstadd_front(&list, node2);
	if (list != node2)
		err++;
	if (list->content != &value2)
		err++;
//	printf("%p\n", list->next);
	if (list->next != node1)
		err++;
	if (list->next->content != &value1)
		err++;
	if (list->next->next != NULL)
		err++;
	node3 = ft_lstnew(&value3);
	ft_lstadd_front(&list, node3);
	if (list != node3)
		err++;
	if (list->content != &value3)
		err++;
	if (list->next != node2)
		err++;
	if (list->next->content != &value2)
		err++;
	if (list->next->next != node1)
		err++;
	if (list->next->next->content != &value1)
		err++;
	if (list->next->next->next != NULL)
		err++;
	printf("ft_lstadd_front total errors: %d\n", err);
	return (err);
}

int		*aux_new_ptr(int value)
{
	int	*i;

	i = malloc(sizeof(int) * 1);
	*i = value;
	return(i);
}

int	test_ft_lstsize_bonus(void)
{
	int		err;
	int		i;
	t_list	*list;
	t_list	*node;

	err = 0;

	node = ft_lstnew(aux_new_ptr(0));
	if (ft_lstsize(node) != 1)
		err++;

	list = NULL;
	if (ft_lstsize(list) != 0)
		err++;

	list = ft_lstnew(aux_new_ptr(1));
	ft_lstadd_front(&list, node);

	i = 2;
	while (i < 10)
	{
		node = ft_lstnew(aux_new_ptr(i));
		ft_lstadd_front(&list, node);
		i++;
	}
	if (ft_lstsize(list) != 10)
		err++;

	printf("ft_lstsize total errors: %d\n", err);
	return (err);
}

int test_ft_lstlast_bonus(void)
{
	int	err;
	int	value1;
	int	value2;
	t_list	*list;
	t_list	*node1;
	t_list	*node2;

	err = 0;
	node1 = ft_lstnew(&value1);
	if (ft_lstlast(node1) != node1)
		err++;
	node2 = NULL;
	if (ft_lstlast(node2) != NULL)
		err++;
//	printf("%p\n", node1);
	node2 = ft_lstnew(&value2);
//	printf("%p\n", node2);
	list = node1;
	ft_lstadd_front(&list, node2);
	if (ft_lstlast(list) != node1)
		err++;
	printf("ft_lstlast total errors: %d\n", err);
	return (err);
}

int	test_ft_lstadd_back(void)
{
	int	err;
	int	value1;
	int	value2;
	int	value3;
	t_list	*list;
	t_list	**list2;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	err = 0;
	list2 = NULL;
	node1 = NULL;
	ft_lstadd_back(list2, node1);
	if (list2 != NULL)
		err++;

	list = NULL;
	ft_lstadd_back(&list, node1);
	if (list != NULL)
		err++;

	list = node1;
	node2 = ft_lstnew(&value2);
//	printf("%p\n", node2);
	ft_lstadd_back(&list, node2);
	if (list != node2)
		err++;

	node1 = ft_lstnew(&value1);
	list = node1;
//	printf("%p\n", node1);
	ft_lstadd_back(&list, node2);
	if (list != node1)
		err++;
	if (list->content != &value1)
		err++;
	if (list->next != node2)
		err++;
	if (list->next->content != &value2)
		err++;
	if (list->next->next != NULL)
		err++;

	node3 = ft_lstnew(&value3);
	ft_lstadd_back(&list, node3);
	if (list != node1)
		err++;
	if (list->content != &value1)
		err++;
	if (list->next != node2)
		err++;
	if (list->next->content != &value2)
		err++;
	if (list->next->next != node3)
		err++;
	if (list->next->next->content != &value3)
		err++;
	if (list->next->next->next != NULL)
		err++;
	printf("ft_lstadd_back total errors: %d\n", err);
	return (err);
}

void	del_one(void *ptr)
{
	free(ptr);
}

int	test_ft_lstdelone(void)
{
	int	err;
	int	*ptr;
	int	*ptr2;
	t_list	*node1;
	t_list	*node2;
	t_list	*list;

	err = 0;
	ptr = malloc(sizeof(int));
	node1 = ft_lstnew(ptr);
	list = NULL;
	ft_lstadd_back(&list, node1);
	ptr2 = malloc(sizeof(int));
	node2 = ft_lstnew(ptr2);
	ft_lstadd_back(&list, node2);
	ft_lstdelone(list, del_one);

	//use Valgrind here and check what it says
	//if (node1->content == ptr)
	//	err++;
	//if (node1->next == NULL)
	//	err++;

	printf("ft_lstdelone total errors: %d\n", err);
	return (err);
}

int	test_ft_lstclear(void)
{
	int	err;
	int	*ptr;
	int	*ptr2;
	t_list	*node1;
	t_list	*node2;
	t_list	*list;

	err = 0;
	ptr = malloc(sizeof(int));
	node1 = ft_lstnew(ptr);
	list = NULL;
	ft_lstadd_back(&list, node1);
	ptr2 = malloc(sizeof(int));
	node2 = ft_lstnew(ptr2);
	ft_lstadd_back(&list, node2);
	ft_lstclear(&list, del_one);

	//use Valgrind here and check what it says
	//if (node1->content == ptr)
	//	err++;
	//if (node1->next == NULL)
	//	err++;
	//if (node2->content == ptr2)
	//	err++;
	//if (node2->next == NULL)
	//	err++;

	ptr = malloc(sizeof(int));
	node1 = ft_lstnew(ptr);
	list = NULL;
	ft_lstadd_back(&list, node1);
	ptr2 = malloc(sizeof(int));
	node2 = ft_lstnew(ptr2);
	ft_lstadd_back(&list, node2);
	ft_lstclear(&node2, del_one);

	if (node1->content != ptr)
		err++;
	if (node1->next == NULL)
		err++;
	//valgrind
	//if (node2->content == ptr2)
	//	err++;
	//if (node2->next == NULL)
	//	err++;
	printf("ft_lstclear total errors: %d\n", err);
	return (err);
}

void	print_content(void	*content)
{
	printf("a%d\n", *(int*)(content));
}

void	set_42(void *content)
{
	*(int *)content = 42;
}

int	test_ft_lstiter(void)
{
	int	err;
	int	value1;
	int	value2;
	int	*ptr;
	int	*ptr2;
	t_list	*node1;
	t_list	*node2;
	t_list	*list;

	err = 0;
	value1 = 0;
	value2 = 1;
	ptr = &value1;
	ptr2 = &value2;

	node1 = ft_lstnew(ptr);
	list = NULL;
	ft_lstadd_back(&list, node1);
	node2 = ft_lstnew(ptr2);
	ft_lstadd_back(&list, node2);

	ft_lstiter(list, print_content);
	ft_lstiter(list, set_42);
	ft_lstiter(list, print_content);

	printf("ft_lstiter total errors: %d\n", err);
	return (err);
}

void	*set_42_v2(void *content)
{
	void	*cont2;

	cont2 = malloc(sizeof(int));

	*(int *)cont2 = 42;
	return (cont2);
}

int	test_ft_lstmap(void)
{
	int	err;
	int	value1;
	int	value2;
	int	*ptr;
	int	*ptr2;
	t_list	*node1;
	t_list	*node2;
	t_list	*list;
	t_list	*list2;

	err = 0;
	value1 = 0;
	value2 = 1;
	ptr = &value1;
	ptr2 = &value2;

	list = NULL;
	list2 = ft_lstmap(list, set_42_v2, del_one);
	ft_lstiter(list, print_content);
	ft_lstiter(list2, print_content);
	
	node1 = ft_lstnew(ptr);
	ft_lstadd_back(&list, node1);
	list2 = ft_lstmap(list, set_42_v2, del_one);
	ft_lstiter(list, print_content);
	ft_lstiter(list2, print_content);

	node2 = ft_lstnew(ptr2);
	ft_lstadd_back(&list, node2);
	list2 = ft_lstmap(list, set_42_v2, del_one);
	ft_lstiter(list, print_content);
	ft_lstiter(list2, print_content);
	//ft_lstiter(list, set_42);
	//ft_lstiter(list, print_content);

	printf("ft_lstmap total errors: %d\n", err);
	return (err);
}

int	main(int argc, char **argv)
{
	srand(time(NULL));
	test_ft_isalpha();		//done && tested
	test_ft_isdigit();		//done && tested
	test_ft_isalnum();		//done && tested
	test_ft_isascii();		//done && tested
	test_ft_isprint();		//done && tested
	test_ft_strlen();		//done && tested
	test_ft_memset();		//done && tested
	test_ft_bzero();		//done && tested
	test_ft_memcpy();		//done && tested
	test_ft_memmove();		//done
	test_ft_strlcpy();		//done && tested
	test_ft_strlcat();		//done
	test_ft_toupper();		//done && tested
	test_ft_tolower();		//done && tested
	test_ft_strchr();		//done && tested
	test_ft_strrchr();		//done && tested
	test_ft_strncmp();		//done && tested
	test_ft_memchr();		//done && tested
	test_ft_memcmp();		//done && tested
	test_ft_strnstr();		//done && tested
	test_ft_atoi();			//done && tested
	test_ft_calloc();		//done
	test_ft_strdup();		//done
	test_ft_substr();		//done && tested
	test_ft_strjoin();		//done && tested
	test_ft_strtrim();
	test_ft_split();		//done
	test_ft_itoa();			//done && tested
	test_ft_strmapi();		//done && tested
	test_ft_striteri();		//done && tested
	test_ft_putchar_fd();	//done
	test_ft_putstr_fd();	//done
	test_ft_putendl_fd();	//done
	test_ft_putnbr_fd();	//done

	if (argc > 1)
	{
		if (test_ft_lstnew_bonus())		//done && tested
			return (0);
		if (test_ft_lstadd_front())		//done && tested
			return (0);
		if (test_ft_lstsize_bonus())	//done && tested
			return (0);
		if (test_ft_lstlast_bonus())	//done && tested
			return (0);
		if (test_ft_lstadd_back())		//done && tested
			return (0);
		if (test_ft_lstdelone())		//done && tested (valgrind)
			return (0);
		if (test_ft_lstclear())			//done && tested (valgrind)
			return (0);
		if (test_ft_lstiter())			//done && tested (terminal)
			return (0);
		if (test_ft_lstmap())			//done && tested (terminal)
			return (0);
	}
	return (0);
}
