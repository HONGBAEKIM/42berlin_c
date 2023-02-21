#include <unistd.h>

int ft_atoi(char *str)
{
	int	neg;
	int	result;
	int	i;

	i = 0;
	neg = 1;
	result = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = -neg;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * neg);
}

void ft_putchar(char c)
{
	write (1, &c, 1);
}

void ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
	}
}

int main(int ac, char **av)
{
	int	i;
	int	nb;

	i = 1;
	nb = ft_atoi(av[1]);
	
	if (ac != 2)
		write(1, "\n", 1);
	else
	{
		while (i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(nb);
			write(1, " = ", 3);
			ft_putnbr(i * nb);
			write(1, "\n", 1);
			i++;
		}
	}
}