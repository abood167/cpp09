#include "RPN.hpp"

//reverse polish notation


int main(int argc, char **argv)
{
    try
    {
        if(argc != 2)
            std::cout << "Wrong number of arguments" << std::endl;
          else
          {
            
            RPN rpn;
            rpn.calculate(argv[1]);
          }

          
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
 
    return 0;
}