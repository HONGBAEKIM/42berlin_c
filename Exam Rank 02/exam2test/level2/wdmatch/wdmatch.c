
#include <unistd.h>
#include <stdio.h>

void    ft_putstr(char *str)
{
    int i = 0;

    while (str[i])
        write(1, &str[i++], 1);
}

int	main(int ac, char **av)
{
	int i = 0;
	int j = 0;

	if (ac == 3)
	{
		while (av[2][i])
        {
			if (av[1][j] == av[2][i])
            	j++;
			i++;
        }
        if (av[1][j] == '\0')
			ft_putstr(av[1]);
	}
	write(1, "\n", 1);
}

