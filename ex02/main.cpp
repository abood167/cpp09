#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
            clock_t start, end;
            clock_t start1, end1;
    try
    {
    for(int i = 0; i < argc -1; i++)
    {
        if(argv[i][0] == '\0')
            throw std::invalid_argument("Error: not a  number.");  
    }
        if(argc <= 1)
            std::cout << "Wrong number of arguments" << std::endl;
        else
        {
   
            PmergeMe pmm;

            pmm.cheackNum(argv,argc);
            start = clock();
            pmm.pushToVector();
            pmm.fordJonson_ALgrathm();
            pmm.backToarr();
            end = clock();
            start1 = clock();
            pmm.pushTodeque();
            pmm.fordJonson_ALgrathm_deque();
            pmm.backToarr_deque();
            end1 = clock();
            std::cout << "Time to process a range of" <<" " << argc -1<< " elements with std::[vector] : " << (double)(end - start)  << "us" << std::endl;
            std::cout << "Time to process a range of" <<" " << argc -1<< " elements with std::[deque] : " << (double)(end1 - start1)  << "us" << std::endl;


          
          
        }

          
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    
}