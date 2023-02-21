
/* Write a function that takes a byte, swaps its halves (like the example) 
and returns the result. */

#include <unistd.h>
#include <stdio.h>

/* unsigned char	swap_bits(unsigned char octet)
{
    return ((octet >> 4) | (octet << 4));
}

void	print_bits(unsigned char octet)
{
    int i = 7;
    unsigned char bit;

    while (i >= 0)
    {
        bit = ((octet >> i) & 1) + '0';
        //printf("i : %d\n", i);
        write (1, &bit, 1);
        //printf("bit : %d\n\n", bit);
        i--;
    }
}
 */


unsigned char	swap_bits(unsigned char octet)
{
    return ((octet >> 4) | (octet << 4));
}

void	print_bits(unsigned char octet)
{
    int i = 7;
    unsigned char bit;

    while (i >= 0)
    {
        bit = ((octet >> i) & 1) + '0';
        write (1, &bit, 1);
        i--;
    }
}

/* unsigned char	reverse_bits(unsigned char octet)
{
    int i = 8;
    unsigned char ret = 0;

    while (i > 0)
    {
        printf("i : %d", i);
        printf("\n");
        ret = ret * 2 + (octet % 2);
        printf("ret : %d", ret);
        printf("\n");
		octet = octet / 2;
        printf("octet : %d", octet);
        printf("\n");
		i--;
    }
    printf("final ret : %d", ret);
    printf("\n");
    return (ret);

} */

unsigned char	reverse_bits(unsigned char octet)
{
    int i = 8;
    unsigned char ret = 0;

    while (i > 0)
    {
        ret = ((ret * 2) + (octet % 2));
        octet = octet / 2;
        i--;
    }
    return (ret);
}



int main()
{
    unsigned char octet;

    octet = 64;
    //print_bits(octet);
    printf("\n");
    //print_bits(swap_bits(octet));
    print_bits(reverse_bits(octet));
    //  0000 0010
    //->0100 0000
    
    /* octet = 2;
    print_bits(octet);
    printf("\n");
    octet = 3;
    print_bits(octet);
    printf("\n");
    octet = 4;
    print_bits(octet);
    printf("\n");
    octet = 5;
    print_bits(octet);
    printf("\n");
    octet = 6;
    print_bits(octet);
    printf("\n");
    octet = 7;
    print_bits(octet);
    printf("\n");
    octet = 8;
    print_bits(octet);
    printf("\n"); */
    //print_bits(swap_bits(octet));
}