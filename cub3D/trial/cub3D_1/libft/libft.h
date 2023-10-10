/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:49:26 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/08 15:52:32 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

/* typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list; */
/*Content : the date contained in the element.
The void pointer can store any type of date type.

struct s_list	*next;
As a pointer that saves the address of the next node,
this pointer acts as a link to each node.
*/

u_int32_t	ft_atoi_base(const char *nptr, int base);
void		*ft_memset(void *str, int c, size_t n);
void		ft_bzero(void *str, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		ft_bzero(void *str, size_t n);
void		*ft_memchr(const void *str, int c, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		ft_striteri(char *str, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_atoi(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_printf(const char *str, ...);
int			ft_putchar(char c, int *len);
int			ft_putstr(char *str, int *len);
int			ft_print_memory(void *addr, int *len);
int			ft_putnbr(int n, int *len);
int			ft_putnbr_u(unsigned int n, int *len);
int			ft_puthex(int n, char c, int *l);
int			ft_strcmp(char *s1, char *s2);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, char *src, size_t size);
size_t		ft_split_count(const char *s, char c);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
char		*ft_strnstr(const char *str, const char *find, size_t len);
char		*ft_strdup(const char *str);
char		*ft_substr(char const *str, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *str, char (*f)(unsigned int, char));
char		*ft_uitoa_base(unsigned long nbr, char *base);

#endif
