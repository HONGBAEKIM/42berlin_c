
#include <unistd.h>

/* int main(int ac, char **av)
{
    int i;

    i = 0;
    if (ac == 2)
    {
        while(av[1][i])
        {
            if ('A' <= av[1][i] && av[1][i] <= 'Z')
                av[1][i] = 'Z' - av[1][i] + 'A';
            else if ('a' <= av[1][i] && av[1][i] <= 'z')
                av[1][i] = 'z' - av[1][i] + 'a';
            write(1, &av[1][i], 1);
            i++;
        }
    }
    write (1, "\n", 1);
} */


int main(int ac, char **av)
{
    int i;

    i = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            if ('a' <= av[1][i] && av[1][i] <= 'z')
                av[1][i] = 'z' - av[1][i] + 'a';
            else if ('A' <= av[1][i] && av[1][i] <= 'A')
                av[1][i] = 'Z' - av[1][i] + 'A';
            write (1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}