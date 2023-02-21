
#include <string.h>
#include <stdio.h>
#include <unistd.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t i;
    size_t j;

    i = 0;
    while (s[i])
    {
        j = 0;
        while (reject[j])
        {
            if (reject[j] == s[i])
                return (i);
            j++;
        }
        i++;
    }
    return (i);
}




int main()
{
    char *str1 = "Hello man";
    char *str2 = "m";
    int re;
    int re2;
   
    re = strcspn(str1, str2);
    re2 = ft_strcspn(str1, str2);

    printf("1. : %d\n", re);
    printf("2. : %d\n", re2);
   
}