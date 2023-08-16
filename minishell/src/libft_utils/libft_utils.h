/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:25:03 by rtimsina          #+#    #+#             */
/*   Updated: 2023/08/14 17:17:33 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_UTILS_H
# define LIBFT_UTILS_H
# include "../main.h"

t_list	*ft_lstdup(t_list *lst);
int		ft_strcmp(char *s1, char *s2);
void	ft_lst_sort_str(t_list **lst, int (*op)(char *, char *));
void	ft_lstdel_int(void *data);
char	*ft_strcpy(char	*dest, const char *src);
char	*ft_strncpy(char *dest, char *src, size_t n);
char	*ft_strcat(char *dest, char *src);
int		ft_isspace(char c);
void	ft_lstdel_first(t_list **lst, void (*del)(void*));
void	ft_lstdel_last(t_list *lst, void (*del)(void*));
void	ft_dlstclear(t_dlist **lst, void (*del)(void*));
void	ft_dlstdelone(t_dlist *lst, void (*del)(void*));
void	ft_lstclear_if(t_list **lst, int (*cmp)(void *), void (*del)(void *));
int		ft_strisspace(char *str);
char	*ft_strtrim_all(const char *s1, const char *set);
int		ft_strisnumber(char *s);
void	*ft_lst_get_data_last_node(t_list *lst);
void	free_arr(void **ptr);
t_dlist	*ft_dlstnew(void *data);
void	ft_dlstadd_front(t_dlist **lst, t_dlist *new);

#endif
