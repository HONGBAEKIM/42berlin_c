# include "BitcoinExchange.hpp"

int main(int ac, char *av[]) 
{
    if (ac != 2)
    {
        std::cout << "ac != 2" << std::endl;
        exit(1);
    }
    BitcoinExchange converter(av[1]);
    return (0);
}
