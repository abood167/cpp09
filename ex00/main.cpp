#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    try
    {
        if(argc != 2)
            std::cout << "Wrong number of arguments" << std::endl;
          else
          {
            
            BitcoinExchange btc;
            btc.findTheExchange(argv[1]);
          }


          
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
 
    
}
