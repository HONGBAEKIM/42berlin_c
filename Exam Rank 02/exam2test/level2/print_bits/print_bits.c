
#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
    int i = 8;
    unsigned char bit;

    while (i > 0)
    {
        i--;
        bit = (octet >> i & 1) + '0';
        write(1, &bit, 1);
    }
}

int main()
{
    print_bits(2);
}

