
/* Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* unsigned char	reverse_bits(unsigned char octet)
{
    int i = 8;
    unsigned char result = 0;

    while (i > 0)
    {
        result = result * 2 + (octet % 2);
		octet = octet / 2;
		i--;
    }
    return (result);
}
 */
unsigned char	reverse_bits(unsigned char octet)
{
    unsigned char   ret = 0;
    int i = 8;

    while (i > 0)
    {
        ret = ret * 2 + (octet % 2);
        octet = octet / 2;
        i--;
    }
    return (ret);
}

void	print_bits(unsigned char octet)
{
    unsigned char   bit;
    int i = 8;

    while (i > 0)
    {
        bit = (octet >> i & 1) + '0';
        write (1, &bit, 1);
        i--;
    }
}


int	main(void)
{
	unsigned char c;

    c = '1';
    print_bits(2);
	print_bits(reverse_bits(2));
}