/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:25:02 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/13 11:25:13 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef MAX_INT
#  define MAX_INT 2147483647
# endif
# ifndef HEXLOWBASE
#  define HEXLOWBASE "0123456789abcdef"
# endif
# ifndef HEXHIGHBASE
#  define HEXHIGHBASE "0123456789ABCDEF"
# endif
# ifndef DECBASE
#  define DECBASE "0123456789"
# endif

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

//structs
typedef struct t_list
{
	void			*content;
	struct t_list	*next;
}	t_list;
typedef struct t_dlist
{
	void			*content;
	struct t_dlist	*next;
	struct t_dlist	*previous;
}	t_dlist;

//ft_checkers
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

//ft_converters
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

//ft_dolst
t_dlist	*ft_dolstextract_back(t_dlist **lst);
t_dlist	*ft_dolstextract_front(t_dlist **lst);
void	ft_dolstadd_back(t_dlist **lst, t_dlist *new);
void	ft_dolstadd_front(t_dlist **lst, t_dlist *new);
void	ft_dolstclear(t_dlist **lst, void (*del)(void *));
void	ft_dolstdelone(t_dlist *lst, void (*del)(void *));
t_dlist	*ft_dolstlast(t_dlist *lst);
t_dlist	*ft_dolstnew(void *content);

//ft_get_next_line
char	*get_next_line(int fd);

//ft_lst
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

//ft_mem
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

//ft_printf
int		ft_printf(int fd, char const *str, ...);

//ft_put_fd
int		ft_putchar_err(int fd, char c, int *err);
int		ft_putendl_fd(int fd, char *str, int *err);
int		ft_putnbr_err(int fd, int num, char *base, int *err);
int		ft_putnbr_long_err(int fd, unsigned long number, char *base, int *err);
int		ft_putptr_err(int fd, void *ptr, int *err);
int		ft_putstr_err(int fd, char *str, int *err);
int		ft_putunsnbr_err(int fd, unsigned int nbr, char *base, int *err);

//ft_str
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup_free(char **str, size_t newline, char **tmp);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_free(char **s1, char **s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
size_t	ft_strlenchr(char *str, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_substrref(char **s, unsigned int start, size_t len);

#endif
