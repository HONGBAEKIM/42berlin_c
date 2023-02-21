
#include <stdio.h>

/*
int ft_atoi(const char *str)
{
    int i;
    int neg;
    int ret;

    i = 0;
    neg = 1;
    ret = 0;
    while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '-')
    {
        neg = -neg;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while (str[i] && '0' <= str[i] && str[i] <= '9')
    {
        ret = ret * 10 + str[i] - '0';
        i++;
    }
    return (ret * neg);
}*/




int	ft_atoi(const char *str)
{
    int i;
    int neg;
    int result;

    i = 0;
    neg = 1;
    result = 0;
    while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '-')
    {
        neg = -neg;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while ('0' <= str[i] && str[i] <= '9' && str[i])
    {
        result = result * 10 + str[i] - '0';
        i++;
    }
    return (result * neg);
}

int main()
{
    printf("%d\n", ft_atoi("-112i04"));
    printf("%d\n", ft_atoi("    -42inlnq1324"));
}