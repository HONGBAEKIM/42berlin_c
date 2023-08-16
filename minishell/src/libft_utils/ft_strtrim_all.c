/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:12:24 by rtimsina          #+#    #+#             */
/*   Updated: 2023/08/11 11:03:59 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

static	void	concat_all(char *dest, char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		ft_strcat(dest, strs[i]);
		i++;
	}
}

static size_t	get_lenth(char **strs)
{
	size_t	len;

	len = 0;
	while (*strs)
	{
		len += ft_strlen(*strs);
		strs++;
	}
	return (len);
}

char	*ft_strtrim_all(const char *s1, const char *set)
{
	char	*new_str;
	char	**split;
	size_t	new_str_len;

	if (!s1)
		return (0);
	split = ft_split((char *)s1, set[0]);
	if (!split)
		return (0);
	new_str_len = get_lenth(split);
	if (new_str_len == 0)
		return (ft_strdup(""));
	new_str = ft_calloc(new_str_len + 1, sizeof(char));
	if (!new_str)
		return (0);
	concat_all(new_str, split);
	free_arr((void **)split);
	return (new_str);
}
