#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
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

std::unordered_map<std::string,int> findMap;

int find(const std::string& s1, const std::string& s2, int p1, int p2, int size)
{
    if (p1 == size || p2 == size) return 0;
    
    std::stringstream ss;
    ss << p1 << "|" << p2;
    if (findMap.find(ss.str()) != findMap.end())
    {
        return findMap[ss.str()];    
    }
    
    char c = s1[p1];
    int sum1 = 0;
    for(int i=p2; i<size; ++i)
    {
        if (s2[i] == c)
        {
            sum1 = 1 + find(s1, s2, p1+1, i+1, size);
            break;
        }
    }
    
    int sum2 = find(s1, s2, p1+1, p2, size);
    int result = sum1 > sum2 ? sum1 : sum2;
    findMap[ss.str()] = result;
    return result;
}

int main() 
{
    std::string s1, s2;
    getline(std::cin, s1);
    getline(std::cin, s2);
    
    int size = s1.size();
    int sum = find(s1, s2, 0, 0, size);
    
    std::cout << sum << std::endl;  
    return 0;
}
