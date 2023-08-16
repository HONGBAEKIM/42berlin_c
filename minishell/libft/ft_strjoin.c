/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:03:27 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/08 12:03:27 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	new_str_size;
	char	*new_str;

	if (!s1 || !s2)
		return (0);
	new_str_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = malloc(new_str_size * sizeof(char));
	if (!new_str)
		return (0);
	ft_strlcpy(new_str, s1, new_str_size);
	ft_strlcat(new_str, s2, new_str_size);
	return (new_str);
}

/* char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;
	char	*str;

	i = 0;
	j = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	while (s1 && i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && j++ < s2_len)
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	return (str);
}
 */