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
    
    std::stringstream ss {s};
    std::getline(ss ,s, ' ');
    int n = atoi(s.c_str());
    std::getline(ss ,s, ' ');
    int k = atoi(s.c_str());

    std::getline(std::cin, s);
    
    //std::cout << n <<std::endl;
    //std::cout << k <<std::endl;
    //std::cout << s <<std::endl;
    
    int f = n/2;
    int count = 0;
    char max = '0';
    for (int i=0; i<f; ++i)
    {
        if (s[i] != s[n-1-i])
        {
            //std::cout << s[i] << s[n-1-i] <<std::endl;
            ++count;
        }
        
        max = std::max(s[i], max);
        max = std::max(s[n-1-i], max);
        
    }
    max = '9';
    //std::cout << count <<std::endl;
    
    if (count > k)
    {
        std::cout << -1 <<std::endl;
        return 0;
    }
    
    int free = k - count;
    //std::cout << free <<std::endl;
    
    for (int i=0; i<f; ++i)
    {
        if (s[i] == s[n-1-i])
        {
            if (free >= 2)
            {
                s[i] = max;
                s[n-1-i] = max;
                free = free - 2;
            }
        }
        else
        {
            if (free >= 1)
            {
                s[i] = max;
                s[n-1-i] = max;
                free = free - 1;
            }
            else
            {
                if (s[i] > s[n-1-i])
                {
                    s[n-1-i] = s[i];
                }
                else
                {
                    s[i] = s[n-1-i]; 
                }
            }
        }
    }
    
     std::cout << s <<std::endl;
    
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
