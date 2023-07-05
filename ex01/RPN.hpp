#ifndef RNP_HPP
#define RNP_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>


//reverse polish notation
class RPN
{
public:
    RPN(/* args */);
    ~RPN();
    RPN(RPN const &other);
    RPN &operator=(RPN const &other);
    void calculate(std::string str);
};




#endif
