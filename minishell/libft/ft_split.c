/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:47:04 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/11 14:47:04 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wdcount(const char *str, char c)
{
	int	trigger;
	int	count;

	trigger = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (count);
}

static int	ft_word_size(const char *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		i++;
		size++;
	}
	return (size);
}

static void	ft_free(char **str, int j)
{
	while (j)
	{
		free(str[j]);
		j--;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		word;
	int		size;
	char	**str;

	i = 0;
	j = -1;
	word = ft_wdcount(s, c);
	str = (char **)malloc((word + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_word_size(s, c, i);
		str[j] = ft_substr(s, i, size);
		if (!str[j])
			ft_free(str, j);
		i = size + i;
	}
	str[j] = NULL;
	return (str);
}
