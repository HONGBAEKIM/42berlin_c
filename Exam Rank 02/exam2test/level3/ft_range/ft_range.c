














/* 
int	ft_atoi(const char *str)
{
    int i;
    int neg;
    int result;

    i = 0;
    neg = 1;
    result = 0;
    while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '-')
    {
        neg = -neg;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while ('0' <= str[i] && str[i] <= '9' && str[i])
    {
        result = result * 10 + str[i] - '0';
        i++;
    }
    return (result * neg);
}*/








/* int	main(int ac, char **av)
{
	int	*lst;
	int	*head;

	lst = ft_range(ft_atoi(av[1]), ft_atoi(av[2]));
	head = lst;
	while (*lst)
	{
		printf("%i\n", *lst);
		lst++;
	}
	free(head);
	return (0);
} */



/* int	*ft_range(int start, int end)
{
	int	size;
	int	*ret;
	int	*ptr;

	size = end - start;
	if (size)
	{
		ptr = (int *)malloc(sizeof(int) * size);
		if (ptr)
		{
			ret = ptr;
			while (start <= end)
			{
				*ptr = start;
				ptr++;
				start++;
			}
			return (ret);
		}
	}
	return (NULL);
} */

/* int main()
{
	int	*lst;
	int	*head;
	
	lst = ft_range(-1, 2);
	head = lst;
	while (*lst)
	{
		printf("%i\n", *lst);
		lst++;
	}
	free(head);
	return (0);
} */


/* Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3. */



/* int		*ft_range(int start, int end)
{
	int length;

	length = end - start + 1;
	
	int *array;
	array = malloc(sizeof(int) * length);

	int i;
	i = 0;
	while(length > 0)
	{
		array[i] = start;
		start++;
		i++;
		length--;
	}
	return(array);
} */

#include <stdio.h>
#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int	i = 0;
	int	*res;
	int	size = (end - start) + 1; 
	
	res = (int *)malloc(sizeof(int) * size);
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[i] = start + i; 
		i++;
	}
	return (res);
}

int		main(void)
{
	int		*tab;

	tab = ft_range(-3, 0);
	printf("%d\n", tab[0]);
	printf("%d\n", tab[3]);

}


