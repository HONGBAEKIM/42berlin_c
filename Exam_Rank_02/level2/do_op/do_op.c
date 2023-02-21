
#include <stdlib.h>
#include <stdio.h>

/* int main(int ac, char **av)
{
    if (ac == 4)
    {
        if (av[2][0] == '+')
            printf("%d", (atoi(av[1]) + atoi(av[3])));
        if (av[2][0] == '-')
            printf("%d", (atoi(av[1]) - atoi(av[3])));
        if (av[2][0] == '*')
            printf("%d", (atoi(av[1]) * atoi(av[3])));
        if (av[2][0] == '/')
            printf("%d", (atoi(av[1]) / atoi(av[3])));
        if (av[2][0] == '%')
            printf("%d", (atoi(av[1]) % atoi(av[3])));
    }
    printf("\n");
    return (0);
} */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int ac, char **av)
{
    if (ac == 4)
    {
        if (av[2][0] == '*')
            printf("%d" ,atoi(av[1]) * atoi(av[3]));
    }
    printf("\n");
}
