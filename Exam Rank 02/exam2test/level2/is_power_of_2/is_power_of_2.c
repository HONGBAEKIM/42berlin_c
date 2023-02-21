/* 
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n); */


/* #include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
    if (n == 0)
        return (0);
    while (n > 1)
    {
        if (n % 2 == 0)
            n = n / 2;
        else
            return (0);
    }
    return (1);
}

int	main(void)
{
    int i = 0;
    while (i < 11)
    {
        printf("%d i : %d\n", i, is_power_of_2(i));
        i++;
    }
}
 */

 #include <stdio.h>

int         is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n > 1)
	{
		if (n % 2 == 0)
			n = n / 2;
		else
			return (0);
	}
	return (1);
}

int	main(void)
{
    int i = 0;

    while (i < 20)
    {    
        printf("i is %d : %d\n",i ,is_power_of_2(i));
        i++;
    }
}