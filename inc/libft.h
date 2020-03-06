/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:56:26 by tjuana            #+#    #+#             */
/*   Updated: 2020/03/06 17:47:36 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define ABS(value)  ((value) < 0 ? (value * -1) : value)
# define BUFF_SIZE 1024
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_gnl
{
	char			*buff;
	int				fd;
}					t_gnl;

typedef unsigned char	t_byte;
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					get_next_line(const int fd, char **line);
void				ft_putchar(int c);
void				ft_putchar_fd(char c, int fd);
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
char				*ft_strstr(const char *hay, const char *ne);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strnstr(const char *h, const char *n, size_t l);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **ap);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strrev(char *str);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_iswsp(char const c);
int					ft_count_words(char const *s, int i, char c);
void				ft_swap(int *a, int *b);
char				*ft_strndup(const char *s1, size_t len);
size_t				ft_strclen(const char *s, char c);
char				*ft_strcdup(const char *s1, char c);
size_t				ft_strnlen(const char *s, size_t maxlen);
int					*ft_intsplitstr(char const *str, char const *set);
void				ft_putdbl(double n, int p);
int					ft_count_lines(char *str);
size_t				ft_line_len(const char *s);
size_t				ft_countwords(char *str, char sep);
void				ft_lstrev(t_list **l);
size_t				ft_lstcount(t_list *lst);
int					ft_2arrclean(char ***dst);
void				ft_bzero_char(void *b, size_t n);
int					ft_2d_int_arrclean(int ***dst);
#endif
