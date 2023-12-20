#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map> //std::map
# include <iomanip> //std::setw
# include <ctime> //time
# include <fstream> //read file
# include <string> // filename.c_str()
/*
How to implement code
1. Parsing the bitcoin exchange database
2. Parsing the input file
3. Using a container to store Bitcoin exchange rates
4. For each line in the input file, 
   find the closest data in the Bitcoin exchange database
5. Display the result of the value mutiplied by the exchnge rate
*/
/* 
Reason to use 'std::map'
'std::map' provides efficient lookup and ordering
dates as keys
Bitcoin exchange rates as values
 */
class BitcoinExchange
{
    private:
        //struct tm is a calendar time
        //float is value for each data and time
        //bool(*)(const struct tm&, const struct tm&) is comparison function
        std::map<struct tm, float, bool(*)(const struct tm&, const struct tm&)> exchange;
        
        //This function pointer indicates what action should be performed on each entry found in the file.
        //A pointer to a member function of the BitcoinExchange class
        //takes std::pair<struct tm, float>, which is <data, time and some value related with date and time>
        void iterFile(std::string const &filename, void (BitcoinExchange::*entry_ptr)(std::pair<struct tm, float>));
        //To process an entry obtained from parsing a data.csv file.
        void processCsvEntry(std::pair<struct tm, float>);
        
        //To process an entry obtained from parsing an input.txt file.
        void processInputEntry(std::pair<struct tm, float>);
        //const std::string & line:   
        //Represents a line of text that needs to be parsed to extract a pair.
        //const std::string & delimiter: 
        //Represents the delimiter used to separate the components of the pair in the input line.
        std::pair<struct tm, float>	extractPair(std::string const & line, std::string const & delimiter) const;
        //original value * closest lower data
        float	convert(std::pair<struct tm, float>) const;
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const & btc);
        ~BitcoinExchange();
        BitcoinExchange &operator=(BitcoinExchange const & rhs);
        //loading data from data.csv
        void loadCsv(const std::string& filename);
        //loading data from input.txt
        void loadInput(const std::string& filename);
        //print out
        void printResults() const;
        /* 
        error handling
        1)parsing error
        2)input error
         */
        class ParsingException : public std::exception
        {
            public:
                virtual char const *what() const throw()
                {
                    return ("BitcoinExchange::exception: parsing error");
                }
        };
};
bool timeCompare(const struct tm& a, const struct tm& b);
bool badDate(std::string tmp);
#endif
