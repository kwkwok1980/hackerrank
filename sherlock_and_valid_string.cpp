#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


int main() {
    std::string s;
    std::cin >> s;
    std::vector<int> results (26);
    for(auto&& c : s)
    {
        ++results[c-'a'];
    }
    
    std::map<int,int> counts;
    for(auto&& i : results)
    {
        if(i!=0) ++counts[i];  
    }
    
    for(auto&& p : counts)
    {
        //std::cout << p.first << "," << p.second << std::endl;      
    }
    
    bool bValid = false;
    
    if (counts.size() == 1)
    {
        bValid = true;
    }
    else if (counts.size() == 2)
    {
        for(auto&& p : counts)
        {
            if (p.second == 1)
            {
                bValid = true;
            }
        }
    }
    
    std::cout << (bValid ? "YES" : "NO") << std::endl;      
    return 0;
}
