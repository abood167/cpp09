#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << "welcome to Bitcoin Exchange " << std::endl;
    changebitcoins();
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
    if (this != &other)
    {
        this->map = other.map;
    }
    return *this;
}



void print_map(std::string_view comment, const map& m)
{
    std::cout << comment;
    // iterate using C++17 facilities
    // for (const auto& [key, value] : m)
    //     std::cout << '[' << key << "] = " << value << "; ";
 
// C++11 alternative:
//  for (const auto& n : m)
//      std::cout << n.first << " = " << n.second << "; ";
//
// C++98 alternative
 for (map::const_iterator it = m.begin(); it != m.end(); it++)
     std::cout << it->first << " = " << it->second << "; ";
 
    std::cout << '\n';
}

void BitcoinExchange::changebitcoins()
{
    std::ifstream file("data.csv");
    std::string line;
   while ( std::getline(file, line))
   {
        std::istringstream iss(line);
        std::string date;
        std::string price;
        std::getline(iss, date, ',');
        std::getline(iss, price, ',');
        std::stringstream ss(price);
        double d;
        ss >> d;
        map[date] = d;
        
   }
}

void invalidDate(std::string date)
{
    //2012-42-42 
    std::string supline;
    std::string month;
    std::string day;

    std::istringstream streamline(date);
    std::getline(streamline, supline , '-');
    std::getline(streamline, month , '-');
    std::getline(streamline, day , '-');
    std::stringstream stringMonth(month);
    std::stringstream stringDay(day);
    int m;
    int d;
    stringMonth >> m;
    stringDay >> d;
    if (m > 12 || m < 1)
        throw std::invalid_argument("Error: bad input => " + date);

    else if (d > 31 || d < 1)
        throw std::invalid_argument("Error: bad input => " + date);
}

void  BitcoinExchange::findTheExchange(std::string date)
{
    std::ifstream file(date);
    if(file.fail())
        throw std::invalid_argument("Error: bad file=> " + date);
    
    std::string line;
    std::getline(file, line);
    if(line != "date | value")
        throw std::invalid_argument("Error: bad file=> " + date);
    while ( std::getline(file, line ))
    {
        try
        {
            double price;
        std::string supline;
        std::string suplinePrise;
        std::istringstream streamline(line);
        // std::cout << line << std::endl;

        std::getline(streamline, supline,   '|');
        supline.erase(std::remove(supline.begin(), supline.end(), ' '), supline.end());
        supline.erase(std::remove(supline.begin(), supline.end(), '\t'), supline.end());
        invalidDate(supline);
        // std::cout << "\"" << supline << "\""<< std::endl;

        map::iterator it = map.lower_bound(supline);
           
        
        std::getline(streamline, suplinePrise,   '|');
        std::stringstream stringPrice(suplinePrise);
        double d;
        stringPrice >> d;
        if (d < 0)
            throw std::invalid_argument("Error: not a positive number.");
        if (d >= 2147483648)
            throw std::invalid_argument("Error: too large a number.");

        if (it == map.end())
            price = 0;
        else
            price = it->second * d ;

        // (void)price;
        // std::cout <<supline1 << " = " << price << std::endl;
        std::cout << supline << " => " << suplinePrise << " = "<< price << std::endl;      
        // 2011-01-03 => 3 = 0.9  
        
    }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        

    }
 
}


// 2011-01-03 => 3 = 0.9
// 2011-01-03 => 2 = 0.6
// 2011-01-03 => 1 = 0.3
// 2011-01-03 => 1.2 = 0.36
// 2011-01-09 => 1 = 0.32
// Error: not a positive number.
// Error: bad input => 2001-42-42
// 2012-01-11 => 1 = 7.1
// Error: too large a number.