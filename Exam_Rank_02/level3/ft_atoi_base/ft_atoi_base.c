

/* Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* int isblack(char c)
{
    if (c <= 32)
        return (1);
    return (0);
}

int isvalid(char c, int base)
{
    char digits[17] = "0123456789abcdef";
    char digits2[17] = "0123456789ABCDEF";

    while (base--)
    {
        if (digits[base] == c || digits2[base] == c)
            return (1);
    }
    return (0);
}

int value_of(char c)
{
    if ('0' <= c && c <= '9')
        return (c - '0');
    else if ('a' <= c && c <= 'f')
        return (c - 'a' + 10);
    else if ('A' <= c && c <= 'F')
        return (c - 'A' + 10);
    return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
    int i;
    int neg;
    int ret;

    i = 0;
    neg = 1;
    ret = 0;
    while (isblack(str[i]))
        i++;
    if (str[i] == '+')
        i++;
    if (str[i] == '-')
    {
        neg = neg * -1;
        i++;
    }
    while (isvalid(str[i], str_base))
    {
        ret = (ret * str_base) + value_of(str[i]);
        i++;
    }
    return (ret * neg);
}
 */

int ft_no(char c)
{
    if (c <= 32)
        return (1);
    return (0);
}


int	ft_check(char c)
{
	if ('0' <= c && c <= '9')
		return (c - '0');
	else if ('a' <= c && c <= 'f')
		return (c - 'a' + 10);
	else if ('A' <= c && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	value_of(char c, int base)
{
	char digit[17] = "0123456789abcdef";
	char digit2[17] = "0123456789ABCDEF";

	while (base--)
	{
		if (digit[base] == c || digit2[base] == c)
			return (1);
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
    int neg = 1;
    int i = 0;
    int ret = 0;

    while (ft_no(str[i]))
        i++;
    if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		i++;
		neg = -neg;
	}
	while (value_of(str[i], str_base))
	{
		ret = (ret * str_base) + ft_check(str[i]);
		i++;
	}
	return (ret * neg);
}

int		main(void)
{
	printf("%d\n", ft_atoi_base("ff", 16));
    //printf("%d\n", ft_atoi_base("FF", 10));
	return 0;
}
