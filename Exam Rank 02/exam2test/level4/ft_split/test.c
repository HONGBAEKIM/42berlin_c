#include <stdio.h>
#include <stdlib.h>
int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

char *ft_strncpy(char *dest, char *src, int n)
{
	int	i = 0;

	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char    **ft_split(char *str)
{
	int	i = 0;
	int	j = 0;
	int	k = 0;
	char **result;
	int	len = ft_strlen(str);
	int	count = 0;

	while (i < len)
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				i++;
		}
	}
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < len)
	{
		j = i;
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
		{
			j = i;
			while (str[j] && str[j] != ' ' && str[j] != '\t' && str[j] != '\n')
				j++;
			result[k] = (char *)malloc(sizeof(char) * (j - i + 1));
			if (!result[k])
				return (0);
			ft_strncpy(result[k], str + i, j - i);
			result[k][j - i] = '\0';
			k++;
			i = j;
		}
	}
	result[k] = 0;
	return (result);
}

int	main(int ac, char **av)
{
	char **split;
	int	i = 0;

	if (ac == 2)
	{
		split = ft_split(av[1]);
		while (split[i])
		{
			printf("%s\n", split[i]);
			i++;
		}
	}
	printf("\n");
	return (0);
}