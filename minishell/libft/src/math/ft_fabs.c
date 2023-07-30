/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:54:02 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/08 11:24:45 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long double	ft_fabs(long double n)
{
	long double	ret;

	if (n < 0)
		ret = (-1.0) * n;
	else
		ret = n;
	return (ret);
}
