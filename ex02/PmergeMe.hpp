#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <deque>
#include <algorithm>
#include <vector>


typedef std::vector<std::pair<int,int> > vector;
typedef std::deque<std::pair<int,int> > deque;
class PmergeMe
{
private:
vector vector;
deque deque;
char **str;

public:
    PmergeMe(/* args */);
    ~PmergeMe();
    PmergeMe(PmergeMe const &other);
    PmergeMe &operator=(PmergeMe const &other);
    void cheackNum(char **av,int ac);
    void pushToVector();
    // void printVector();
    void fordJonson_ALgrathm();
   void backToarr();
   void backToarr_deque();
   void fordJonson_ALgrathm_deque();
   void pushTodeque();
};



#endif