#include "RPN.hpp"


RPN::RPN(/* args */)
{
}

RPN::~RPN()
{
}

RPN::RPN(RPN const &other)
{
    *this = other;
}

RPN &RPN::operator=(RPN const &other)
{
    (void)other;
    return *this;
}

void RPN::calculate(std::string str)
{
    std::stack<double> stack;
    for (size_t i = 0; i < str.length(); i++)
    {

        if(std::isspace(str[i]))
            ;
        else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || std::isdigit(str[i]) )
        {
            ;
        }
        else
        {
            throw std::invalid_argument("Error: invalid character.");
        }

        if(std::isdigit(str[i]) && std::isdigit(str[i + 1]))
        {
                throw std::invalid_argument("Error: not a positive number.");
        }
        if (str[i] == '-' && std::isdigit(str[i + 1]) )
        {
            throw std::invalid_argument("Error: not a positive number.");
        }
      
        
            
        if(std::isdigit(str[i]))
        {
            int number = str[i] - '0';
            if (number < 0)
                throw std::invalid_argument("Error: not a positive number.");
            stack.push(number);
            
        }
        else if(str[i] == '+')
        {
            double a = stack.top();
            //stack.top :: return the top element of the stack
            stack.pop();
            //stack.pop :: remove the top element of the stack
            double b = stack.top();
            stack.pop();
            stack.push(a + b);
        }
        else if(str[i] == '-')
        {
            double a = stack.top();
            stack.pop();
            double b = stack.top();
            stack.pop();
            stack.push(b - a);
        }
        else if(str[i] == '*')
        {
            double a = stack.top();
            stack.pop();
            double b = stack.top();
            stack.pop();
            stack.push(a * b);
        }
        else if(str[i] == '/')
        {
            double a = stack.top();
            stack.pop();
            double b = stack.top();
            stack.pop();
            stack.push(b / a);
        }  
        
        
    }
    if(stack.size() != 1)
        throw std::invalid_argument("Error: invalid expression.");
    std::cout << stack.top() << std::endl;
}