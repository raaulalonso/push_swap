/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:09:30 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/11 13:51:47 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

typedef struct node
{
	int			data;
	struct node	*next;
}	node_t;

node_t	*ft_lstnew(int content);
void	ft_lstadd_front(node_t **lst, node_t *new);
int		ft_lstsize(node_t *lst);
node_t	*ft_lstlast(node_t *lst);
void	ft_lstadd_back(node_t **lst, node_t *new);
void	ft_lstdelone(node_t *lst, void (*del)(int));
void	ft_lstclear(node_t **lst, void (*del)(int));
void	ft_lstiter(node_t *lst, void (*f)(int));
node_t	*ft_lstmap(node_t *lst, int(*f)(int), void (*del)(int));

int		ft_printf(char const *print, ...);
int		ft_puthex(unsigned int n, int flag);
int		ft_putmem(void *mem);
int		ft_puthexmem(uintptr_t n, int flag);
int		ft_putchar(char c, int fd);
int		ft_putnbr(int n, int fd);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_putstr(char *s, int fd);

#endif