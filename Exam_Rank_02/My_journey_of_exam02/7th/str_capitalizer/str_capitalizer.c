#include <unistd.h>

void	str_capitalizer(char *str)
{
	int	i;

	if ('a' <= str[0] && str[0] <= 'z')
		str[0] -= 32;
	write(1, &str[0], 1);
	i = 1;
	while (str[i])
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 32;
		if (('a' <= str[i] && str[i] <= 'z') && 
			(str[i - 1] == ' ' || str[i - 1] == '\t'))
			str[i] -= 32;
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 2)
		write(1, "\n", 1);
	else
	{
		while (i < ac)
		{
			str_capitalizer(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
}