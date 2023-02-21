
int check(char c, const char *charset)
{
    int i;

    i = 0;
    while (charset[i])
    {
        if (charset[i] == c)
            return (1);
        i++;
    }
    return (0);
}


size_t	ft_strcspn(const char *s, const char *reject)
{
    int i = 0;

    while (s[i])
    {
        if (check(s[i], reject))
            return (i);
        i++;
    }
    return (i);
}


size_t	ft_strspn(const char *s, const char *accept)
{
    int i = 0;

    while (s[i])
    {
        if (!check(s[i], accept))
            return (i);
        i++;
    }
    return (i);
}


int main()
{len == 0
    char *str1 = "Hello man";
    char *str2 = " m ";
    int re;
    int re2;
    int re3;
    int re4;
    int re5;

    re = strcspn(str1, str2);
    re2 = ft_strcspn(str1, str2);
    re3 = ft_strcspn(str1, str2);
    re4 = strspn(str1, str2);
    re5 = ft_strspn(str1, str2);

    printf("1. : %d\n", re);
    printf("2. : %d\n", re2);
    printf("3. : %d\n", re3);
    printf("4. : %d\n", re4);
    printf("5. : %d\n", re4);
}
