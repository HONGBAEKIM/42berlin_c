/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:47:39 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/12 08:48:30 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Removes the set soecufied in s1
start++ until set and s1 is not the same
end-- until set and s1 is not the same
start > end returns '\0' memory 
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1 || !set)
		return (0);
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end && s1[end - 1] && ft_strchr(set, s1[end - 1]))
		end--;
	if (start > end)
		return (ft_strdup(""));
	result = ft_substr(s1, start, end - start);
	return (result);
}
/*
int	main()
{
	printf("%s\n", ft_strtrim("ABCD", "A"));
	printf("%s\n", ft_strtrim("ABCD", "B"));
	printf("%s\n", ft_strtrim("ABCD", "BC"));
	printf("%s\n", ft_strtrim("ABCD", "ABCD"));
	return (0);
}*/
