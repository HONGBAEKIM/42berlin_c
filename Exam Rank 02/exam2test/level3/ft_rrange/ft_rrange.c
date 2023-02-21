
/* Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0. */

#include <stdio.h>
#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int	i = 0;
	int	*ret;
	int	size;

    if (start > end)
        return (ft_rrange(end, start));
	size = (end - start) + 1;
	ret = (int *)malloc(sizeof(int) * size);
	if (!ret)
		return (0);
	while (i < size)
	{
		ret[i] = start + i; 
		i++;
	}
	return (ret);
}

/* int	main(int ac, char **av)
{
	int	*lst;

	lst = ft_rrange(atoi(av[1]), atoi(av[2]));
	while (*lst)
	{
		printf("%i\n", *lst);
		lst++;
	}
	return (0);
} */

int main()
{
	//int	list[] = ft_range(1, 3);
	printf("%i\n", ft_range(0, -3)[0]);
	printf("%i\n", ft_range(0, -3)[1]);
	printf("%i\n", ft_range(0, -3)[2]);
	printf("%i\n", ft_range(0, -3)[3]);
}