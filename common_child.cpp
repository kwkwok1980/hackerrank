#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

void GetStrings(const std::string& s, std::unordered_set<std::string>& values, int count)
{
    if(count == 0)
    {
        values.insert(s);
        return;
    }
        
    int size = s.length();
    for(int i=0; i<size; ++i)
    {
        std::string value = s;
        value.erase(i,1);
        GetStrings(value, values, count-1);
    }
}

int main() 
{
    std::string s1, s2;
    getline(std::cin, s1);
    getline(std::cin, s2);
    //std::cout << s1 << std::endl;
    //std::cout << s2 << std::endl;
    
    int size = s1.size();
    for(int i=0; i<size; ++i)
    {
        std::unordered_set<std::string> values1;
        GetStrings(s1, values1, i);
        
        std::unordered_set<std::string> values2;
        GetStrings(s2, values2, i);
        
        for(const auto& value1 : values1)
        {
            if(std::find(values2.begin(), values2.end(), value1) != values2.end())
            {
                std::cout << size-i << std::endl;
                return 0;    
            }
        }
    }
    std::cout << 0 << std::endl;
    return 0;
}
