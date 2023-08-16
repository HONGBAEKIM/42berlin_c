/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:16:51 by rtimsina          #+#    #+#             */
/*   Updated: 2023/08/11 11:01:23 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

int	ft_strcmp(char *s1, char *s2)
{
	char	*str;
	char	*src;

	str = s1;
	src = s2;
	while (*str == *src && *str)
	{
		str++;
		src++;
	}
	return (*str - *src);
}
