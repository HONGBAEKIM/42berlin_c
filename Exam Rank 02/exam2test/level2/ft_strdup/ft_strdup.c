#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* char    *ft_strdup(char *str)
{
    int i;
    int len;
    char    *newstr;

    i = 0;
    len = 0;
    while (str[len])
        len++;
    newstr = (char *)malloc(sizeof(char) * (len + 1));
    if (!newstr)
        return (0);
    while (str[i])
    {
        newstr[i] = str[i];
        i++;
    }
    newstr[i] = '\0';
    return (newstr);
} */


char    *ft_strdup(char *src)
{
	int	i;
	int	len;
	char *new;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int main()
{
    char *src = "abcd";

    printf("1. %s\n", ft_strdup(src));
    printf("2. %s\n", strdup(src));
}