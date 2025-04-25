#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

std::unordered_set<std::string> GetStrings(const std::unordered_set<std::string>& params)
{
    std::unordered_set<std::string> values;
    if (params.size() == 0)
    {
        return values;    
    }
    
    int size = params.begin()->size();
    for(const auto& param : params)
    {
        for(int i=0; i<size; ++i)
        {
            std::string value = param;
            value.erase(i,1);
            values.insert(value);
        }
    }
    return values;
}

int main() 
{
    std::string s1, s2;
    getline(std::cin, s1);
    getline(std::cin, s2);
    //std::cout << s1 << std::endl;
    //std::cout << s2 << std::endl;
    
    int size = s1.size();
    if (s1 == s2)
    {
        std::cout << size << std::endl;  
        return 0;
    }
    
    std::unordered_set<std::string> values1;
    std::unordered_set<std::string> values2;
    
    values1.insert(s1);
    values2.insert(s2);
    
    for(int i=0; i<size; ++i)
    {
        values1 = GetStrings(values1);
        values2 = GetStrings(values2);
        
        for(const auto& value1 : values1)
        {
            if(std::find(values2.begin(), values2.end(), value1) != values2.end())
            {
                std::cout << size-i-1 << std::endl;
                return 0;    
            }
        }
    }
    std::cout << 0 << std::endl;
    return 0;
}
