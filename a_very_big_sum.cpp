#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int n;    
    std::string s;        
    std::getline(std::cin, s);    
    n = ::atoi(s.c_str());        
    int i;    
    long long int sum = 0;    
    while(std::getline(std::cin, s, ' '))    
    {        
        i = ::atoi(s.c_str());        
        //std::cout << "-" << i << "-" << std::endl;        
        sum += i;    
    }        
    std::cout << sum << std::endl;        
    return 0;
}
