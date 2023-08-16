/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:00:54 by rtimsina          #+#    #+#             */
/*   Updated: 2023/08/11 11:03:08 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

char	*ft_strcpy(char	*dest, const char *src)
{
	if (!src)
		return (NULL);
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*str;

	str = dest;
	if (!src)
		return (NULL);
	while (*str)
		str++;
	while (*src)
		*str++ = *src++;
	*str = '\0';
	return (str);
}
