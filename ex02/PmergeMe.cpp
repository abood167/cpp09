#include "PmergeMe.hpp"

PmergeMe::PmergeMe(/* args */):vector(),deque(),str()
{
    
}

PmergeMe::~PmergeMe()
{
}


PmergeMe::PmergeMe(PmergeMe const &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
    this->vector = other.vector;
    this->deque = other.deque;
    this->str = other.str;

    return *this;
}

void PmergeMe::cheackNum(char **av,int ac)
{
    for (int i = 1; i < ac; i++)
    {
        for (size_t j = 0; j < strlen(av[i]); j++)
        {
            if (av[i][j] < '0' || av[i][j] > '9')
                throw std::invalid_argument("Error: not a positive number.");
            
        }
    }
    str = &(av[1]);
    for (size_t i = 0; str[i] != '\0'; i++)
    {
    // std::cout << "str: " << str[i] << std::endl;
;
        /* code */
    }
    
    

}

void PmergeMe::pushToVector()
{
    std::pair<int,int> pair;
    
    for (int i = 0; str[i] != '\0'; i++)
    {
        if(i % 2 == 0)
        {
           long y = atol(str[i]);
              if (y > INT_MAX)
                throw std::invalid_argument("Error: not in a range number.");

            vector.push_back(std::make_pair(atoi(str[i]),-1));

        }
        else
        {
            vector.rbegin()->second = atoi(str[i]);
            if(vector.rbegin()->first < vector.rbegin()->second)
                std::swap(vector.rbegin()->first,vector.rbegin()->second);
                
        }


    }
    // for (size_t i = 0; i < vector.size(); i++)
    // {
    //     std::cout << vector[i].first << " " << vector[i].second << std::endl;
    // }
}
void PmergeMe::pushTodeque()
{
    std::pair<int,int> pair;
    
    for (int i = 0; str[i] != '\0'; i++)
    {
        if(i % 2 == 0)
            deque.push_back(std::make_pair(atoi(str[i]),-1));
        else
        {
            deque.rbegin()->second = atoi(str[i]);
            if(deque.rbegin()->first < deque.rbegin()->second)
                std::swap(deque.rbegin()->first,deque.rbegin()->second);
                
        }


    }
    // for (size_t i = 0; i < vector.size(); i++)
    // {
    //     std::cout << vector[i].first << " " << vector[i].second << std::endl;
    // }
    // std::cout << "deque" << std::endl;
    // std::cout << "deque" << std::endl;
}



void merge(vector& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    vector leftArr(n1), rightArr(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of leftArr, if any
    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of rightArr, if any
    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}


void merge_deque(deque& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    deque leftArr(n1), rightArr(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of leftArr, if any
    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of rightArr, if any
    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}



void mergeSort(vector& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}
void mergeSort_deque(deque& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort_deque(arr, left, mid);
        mergeSort_deque(arr, mid + 1, right);

        // Merge the sorted halves
        merge_deque(arr, left, mid, right);
    }
}


void PmergeMe::fordJonson_ALgrathm()
{
    // std::cout << "before merge sort: " << std::endl;
    // for (size_t i = 0; i < vector.size(); i++)
    // {
    //     std::cout << vector[i].first << " " << vector[i].second << std::endl;
    // }
    mergeSort(vector,0,vector.size() - 1);
    // std::cout << "after merge sort: " << std::endl;
    // for (size_t i = 0; i < vector.size(); i++)
    // {
    //     std::cout << vector[i].first << " " << vector[i].second << std::endl;
    // }
    
}
void PmergeMe::fordJonson_ALgrathm_deque()
{
    // std::cout << "before merge sort: " << std::endl;
    // for (size_t i = 0; i < deque.size(); i++)
    // {
    //     std::cout << deque[i].first << " " << deque[i].second << std::endl;
    // }
    mergeSort_deque(deque,0,deque.size() - 1);
    // std::cout << "after merge sort: " << std::endl;
    // for (size_t i = 0; i < deque.size(); i++)
    // {
    //     std::cout << deque[i].first << " " << deque[i].second << std::endl;
    // }
    
}

void PmergeMe::backToarr()
{
 std::vector<int> sorted_vector;
    for (size_t i = 0; i < vector.size(); i++)
    {
        sorted_vector.push_back(vector[i].first);
        std::vector<int>::iterator it = std::lower_bound(sorted_vector.begin(), sorted_vector.end(), vector[i].second);
        sorted_vector.insert(it, vector[i].second);
    }
    // for (size_t i = 1; i < sorted_vector.size(); i++)
    // {
    //     std::cout << " "<< sorted_vector[i];
    // }
    // std::cout << std::endl;
}
void PmergeMe::backToarr_deque()
{
 std::deque<int> sorted_deque;
    for (size_t i = 0; i < deque.size(); i++)
    {
        sorted_deque.push_back(deque[i].first);
        std::deque<int>::iterator it = std::lower_bound(sorted_deque.begin(), sorted_deque.end(), deque[i].second);
        sorted_deque.insert(it, deque[i].second);
    }
    std::cout << "before : ";
       for (size_t i = 0; str[i] != '\0'; i++)
    {
    std::cout << " " << str[i];

        /* code */
    }
    std::cout << std::endl;
    std::cout << "after : ";
    if (*sorted_deque.begin() == -1)
        sorted_deque.pop_front();
    for (size_t i = 0; i < sorted_deque.size(); i++)
    {
        std::cout << " "<< sorted_deque[i];
    }   
    std::cout << std::endl;
}