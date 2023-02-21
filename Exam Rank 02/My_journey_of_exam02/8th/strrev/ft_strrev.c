
#include <stdio.h>

char    *ft_strrev(char *str)
{
    int i;
    int len;
    char    tmp;

    i = 0;
    len = 0;
    while (str[len])
        len++;
    while (i < len)
    {
        len--;
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
        i++;
    }
    return (str);
}
#include <stdio.h>

int main()
{
    char str[] = "abcdefg";

    printf("%s\n", ft_strrev(str));
}