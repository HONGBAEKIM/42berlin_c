# include "BitcoinExchange.hpp"

# include <iostream>


BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::~BitcoinExchange()
{
    
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & btc)
{
    *this = btc;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
    if (this != &rhs)
        exchange = rhs.exchange;
    return *this;
}

void BitcoinExchange::loadCsv(const std::string& filename)
{

}

void BitcoinExchange::loadInput(const std::string& filename)
{

}

void BitcoinExchange::printResults() const
{

}



bool badDate(std::string tmp)
{
    std::stringstream ss;
    //0000-XX-00
    //month
    ss << tmp.substr(5, 2);
    unsigned int month;
    //'>>' is extract value
    ss >> month;
    ss.clear();
    //0000-00-XX
    //date
    ss << tmp.substr(8, 2);
    unsigned int day;
    ss >> day;

    // Check if the extracted month and day are within valid ranges
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return true;

    return false;
}
