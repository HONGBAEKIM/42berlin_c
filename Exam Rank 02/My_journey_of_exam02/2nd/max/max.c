

#include <stdio.h>

/* int		max(int* tab, unsigned int len)
{
    int result = 0;
    int i = 0;

    if (!tab)
        return (0);
    result = tab[i];
    while (i < len)
    {
        if (result < tab[i])
        {
            result = tab[i];
        }
        i++;
    }
    return (result);
}
 */



/* Assignment name  : max
Expected files   : max.c
Allowed functions:
-----------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, 
the second is the number of elements in the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0. */



int		max(int* tab, unsigned int len)
{
    int ret = 0;
    unsigned int i = 0;

    ret = tab[i];
	if (!tab)
		return (0);
    while (i < len)
    {
        if (ret < tab[i])
            ret = tab[i];
        i++;
    }
    return (ret);
}


int main()
{
    int tab[] = {5, 42, 0, 33, 43};
	int tab2[] = {};

    printf("max : %d\n", max(tab, 5));
	printf("max : %d\n", max(tab2, 0));
}

