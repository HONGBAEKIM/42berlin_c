/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:54:33 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/11 16:54:54 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_split_count(const char *s, char c)
{
	size_t	i;
	size_t	prev;
	size_t	next;
	size_t	size;
	size_t	counter;

	i = 0;
	prev = i;
	next = i;
	counter = 0;
	while (1)
	{
		if (s[i] == c || s[i] == '\0')
			next = i;
		size = next - prev;
		if (size > 1 || (size == 1 && s[i - 1] != c))
			counter++;
		if (s[i] == '\0')
			break ;
		prev = next;
		i++;
	}
	return (counter);
}

size_t	ft_addpart(char **result, const char *prev, size_t size, char c)
{
	if (*prev == c)
	{
		prev++;
		size--;
	}
	*result = (char *)malloc((size + 1) * sizeof(char));
	ft_strlcpy(*result, prev, size + 1);
	return (1);
}

void	ft_createsplit(char **result, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	size;
	size_t	prev;
	size_t	next;

	i = 0;
	j = 0;
	prev = i;
	next = i;
	while (1)
	{
		if (s[i] == c || s[i] == '\0')
			next = i;
		size = next - prev;
		if (size > 1 || (size == 1 && s[i - 1] != c))
			j += ft_addpart(&result[j], &s[prev], size, c);
		if (s[i] == '\0')
			break ;
		prev = next;
		i++;
	}
	result[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc((ft_split_count(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	ft_createsplit(result, s, c);
	return (result);
}

/*
#include "libft.h"

static size_t	ft_count_word(const char *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	if (!s[0])
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			words++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		words++;
	return (words);
}


Deallocate or release the memory blocks to reduce their wastage.
dynamically de-allocate the memory.

static void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}


Using malloc 

static char	**ft_my_malloc(const char *s, char c)
{
	char	**ret;

	ret = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	return (ret);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	len;
	size_t	i;

	i = 0;
	ret = ft_my_malloc(s, c);
	if (!s || !ret)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			ret[i] = ft_substr(s - len, 0, len);
			if (!ret[i])
				free_all(ret);
			i++;
		}
		else
			s++;
	}
	ret[i] = 0;
	return (ret);
}
*/

/*
int main()
{
    char **tab;
    unsigned int    i;

    i = 0;
    tab = ft_split(" abc de fg", ' ');
    while (tab[i])
    {
        printf("%s\n", tab[i]);
        i++;
    }
    return (0);
}*/
