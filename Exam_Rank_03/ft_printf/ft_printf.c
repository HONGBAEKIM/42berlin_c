/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:35:00 by hongbaki          #+#    #+#             */
/*   Updated: 2023/04/10 10:35:01 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <unistd.h>
# include <stdarg.h>
#include <stdio.h>

int	ft_putchar(char c, int *len)
{
	*len = *len + 1;
	return (write(1, &c, 1));
}

int	ft_putstr(char *str, int *len)
{
	long unsigned int	i;
	int					ret;

	ret = 0;
	i = 0;
	if (!str)
		ft_putstr("(null)", len);
	else
	{
		while (str[i])
		{
			ret = ft_putchar(str[i], len);
			if (ret < 0)
				return (ret);
			i++;
		}
	}
	return (ret);
}

int	ft_putnbr(int n, int *len)
{
	int	ret;

	ret = 0;
	if (n == -2147483648)
		ret = ft_putstr("-2147483648", len);
	else
	{
		if (n < 0)
		{
			ret = ft_putchar('-', len);
			n = -n;
		}
		if (n > 9)
		{
			ft_putnbr(n / 10, len);
			ft_putnbr(n % 10, len);
		}
		if (n < 10)
		{
			ret = ft_putchar((n % 10) + '0', len);
			if (ret < 0)
				return (ret);
		}
	}
	return (ret);
}

int	ft_puthex(int n, char c, int *l)
{
	unsigned int	u;
	int				ret;

	ret = 0;
	u = (unsigned int)n;
	if (u >= 16)
	{
		ft_puthex(u / 16, c, l);
		ft_puthex(u % 16, c, l);
	}
	else
	{
		if (c == 'x')
			ret = ft_putchar("0123456789abcdef"[u % 16], l);
		else
			ret = ft_putchar("0123456789ABCDEF"[u % 16], l);
		if (ret < 0)
			return (ret);
	}
	return (ret);
}

int	conditions(const char *per_next, va_list *a, int *len)
{
	int	ret;

	ret = 0;
	if (*per_next == 's')
		ret = ft_putstr(va_arg(*a, char *), len);
	else if (*per_next == 'd')
		ret = ft_putnbr(va_arg(*a, int), len);
	else
		ret = ft_puthex(va_arg(*a, int), *per_next, len);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;
	int		error;

	len = 0;
	error = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			error = conditions(++str, &ap, &len);
		else
			error = ft_putchar(*str, &len);
		if (error < 0)
			return (error);
		str++;
	}
	va_end(ap);
	return (len);
}

int	main()
{
	ft_printf("%s\n", "toto");
	printf("%s\n", "toto");
	ft_printf("Magic %s is %d\n", "number", 42);
	printf("Magic %s is %d\n", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("Hexadecimal for %d is %x\n", 42, 42);
}

/* 
#include <limits.h>
int	main()
{
	printf("max %d\n", INT_MAX);
	printf("max %d\n", INT_MIN);
}
 */
