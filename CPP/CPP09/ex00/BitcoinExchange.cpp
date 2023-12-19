# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    //Compare two ''struct tm' objects(which represent calendar time)
    bool(*function_pt)(struct tm const &, struct tm const &) = &timeCompare;
    //soring is determined by the 'timeCompare' function
    exchange = std::map<struct tm, float, bool(*)(struct tm const &, struct tm const &)>(function_pt);
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
    iterFile(filename, &BitcoinExchange::processCsvEntry);
}

void BitcoinExchange::iterFile(std::string const &filename, void (BitcoinExchange::*entry_ptr)(std::pair<struct tm, float>));
{
    //fstream is reading from and writing to files
    //std::ios::in: This flag indicates that the file is to be opened for input operations.
    std::fstream fs (filename.c_str(), std::ios::in);
    // Set to throw an exception on fail
    fs.exceptions(fs.failbit);

    std::string delimiter = "|";
    //filename.rfind(".csv") returns 4,
    //filename is 'data.csv' cus the substring ".csv" start at index 4('d=0', 'a=1', 't=2', 'a=3', '.=4') 
    bool csv = (filename.rfind(".csv") + 4 == filename.length());
    if (csv)
        delimiter = ",";
    
        std::string line;
        std::getline(fs, line);
        
        //goodbit is no error, badbit is error
        fs.exception(fs.goodbit | fs.badbit);
        while (std::getline(fs, line))
        {
            try
            {
                //'entry' is variable
                //'extractPair' is to parse the 'line' based on the 'delimiter' into a pair of struct tm and float
                std::pair<struct tm, float> entry = extractPair(line, delimiter);
                //entry_ptr is the pointer to 'BitcoinExchange'.
                //entry is a std::pair<struct tm, float>.
                (this->*entry_ptr)(entry);
            }
            catch (BitcoinExchange::BadInputException & e)
            {
                if (csv)
				{
					fs.close();
					throw;
				}
				else
					std::cout << e.what() << std::endl;
            }
            catch (BitcoinExchange::BadNumberException & e)
			{
				if (csv)
				{
					fs.close();
					throw;
				}
				else
					std::cout << e.what() << std::endl;
			}
			catch (BitcoinExchange::BadDateException & e)
			{
				if (csv)
				{
					fs.close();
					throw;
				}
				else
					std::cout << e.what() << std::endl;
			}
        }
    //std::ios_base::failure is an exception class in the C++ Standard Library 
    //that is used to report errors that occur during input/output operations.
    catch(std::ios_base::failure & e)
    {
        // Close the file stream before re-throwing the exception
        fs.close();
        // Re-throw the exception for further handling
        throw;
    }
    // Close the file stream if no exceptions were thrown
    fs.close();
}

void BitcoinExchange::processCsvEntry(std::pair<struct tm, float>)
{
    exchange.insert(entry);
}

void BitcoinExchange::loadInput(const std::string& filename)
{

}

void BitcoinExchange::printResults() const
{

}



bool BitcoinExchange::badDate(std::string tmp)
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
