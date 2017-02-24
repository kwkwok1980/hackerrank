#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{    
    std::string s;    
    std::getline(std::cin, s);    
    const int n = ::atoi(s.c_str());    
    //std::cout << n << std::endl;    
    //std::vector<int> values(n*n, 0);    
    int value;    
    int sum1=0, sum2=0;    
    for(int i=0; i<n; ++i)    
    {        
        std::getline(std::cin, s, '\n');        
        std::stringstream ss {s};        
        for(int j=0; j<n; ++j)        
        {            
            std::getline(ss, s, ' ');            
            value = ::atoi(s.c_str());            
            //std::cout << value << std::endl;            
            if (i==j)            
            {               
                sum1 += value;            
            }            
            if (i==(n-1-j))            
            {               
                sum2 += value;            
            }        
        }    
    }    
    //std::cout << sum1 << std::endl;    
    //std::cout << sum2 << std::endl;    
    std::cout << ::abs(sum1-sum2) << std::endl;    
    return 0;
}
