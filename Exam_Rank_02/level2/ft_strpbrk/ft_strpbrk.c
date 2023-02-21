
#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
    int i;

    if (!s1 || !s2)
        return (0);
    while (*s1)
    {
        i = 0;
        while (s2[i])
        {
            if (*s1 == s2[i])
                return ((char *)s1);
            i++;
        }
        s1++;
    }    
    return (0);
}

int main()
{
    const char s1[] = "abcd";
    const char s2[] = "b";

    printf("1. %s\n", ft_strpbrk(s1, s2));
    printf("2. %s\n", strpbrk(s1, s2));
}