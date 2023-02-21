





/* int	ft_count(long nbr)
{
	int	count = 0;
	
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	long	n;
	int	i;
	char	*str;

	n = nbr;
	i = ft_count(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	i--;
	str[i] = '\0';
	if (n == 0)
	{
		str[0] = 0;
		return (0);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (str);	
}

int	main()
{
	printf("%s", ft_itoa(-13));
}
 */


/* Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it 
to a null-terminated string.
The function returns the result in a char array 
that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr); */

#include <stdlib.h>
#include <stdio.h>

int	ft_count(long nbr)
{
	int	count = 0;

	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	long	n;
	int	i;
	int	len;
	char	*str;

	n = nbr;
	len = ft_count(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = len - 1;
	if (n == 0)
	{
		str[0] = '0';
		return (0);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

int	main()
{
	printf("%s", ft_itoa(-1113));
}
