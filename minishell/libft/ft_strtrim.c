/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:05:51 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/09 10:05:51 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		front;
	size_t		rear;
	size_t		i;
	char		*str;

	front = 0;
	i = 0;
	rear = ft_strlen(s1);
	if (s1 == 0 || set == 0)
		return (0);
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	while (rear > front && ft_strchr(set, s1[rear - 1]))
		rear--;
	str = (char *)malloc(sizeof(char) * (rear - front + 1));
	if (!str)
		return (0);
	while (front < rear)
	{
		str[i] = s1[front];
		i++;
		front++;
	}
	str[i] = '\0';
	return (str);
}
