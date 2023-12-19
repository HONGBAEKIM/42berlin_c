# include "BitcoinExchange.hpp"

int main(int ac, char *av[]) 
{
    if (ac != 2)
    {
        std::cout << "argc != 2" << std::endl;
        return (1);
    }

    std::string input(av[1]);
    
    BitcoinExchange bce = BitcoinExchange();
    try
    {
        bce.loadCsv("data.csv");
        bce.loadInput(input);
    }
    catch(BitcoinExchange::CsvParsingException & e)
    {
        std::cout << e.what() << std::endl;
        return (1);
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
        return (1);
    }
    
    return (0);
}
