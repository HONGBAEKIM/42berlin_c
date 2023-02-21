/* 
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$> 
*/

#include <unistd.h>

int ft_alpha_len(char nb)
{
    int count;

    if ('a' <= nb && nb <= 'z')
        count = (nb - 97 + 1);
    else if ('A' <= nb && nb <= 'Z')
        count = (nb - 65 + 1);
    else
        count = 1;
    return (count);
}

int main(int ac, char **av)
{
    int i;
    int len;

    i = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            len = ft_alpha_len(av[1][i]);
            while (len > 0)
            {
                write (1, &av[1][i], 1);
                len--;
            }
            i++;
        }
    }
    write (1, "\n", 1);
}