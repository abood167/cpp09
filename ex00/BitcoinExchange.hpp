#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

typedef std::map<std::string, double, std::greater<std::string> > map;
        void invalidDate(std::string date);

class BitcoinExchange
{
    private:
       map map;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &other);
        BitcoinExchange &operator=(BitcoinExchange const &other);
        void changebitcoins();
        void findTheExchange(std::string date);
      
};



#endif