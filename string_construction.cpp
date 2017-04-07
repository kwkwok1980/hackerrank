#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

void Solve()
{
    std::string s;
    std::cin >> s;
    //std::cout << s << std::endl;
    std::set<char> caches;
    int price = 0;
    for (auto&& c : s)
    {
        //std::cout << c << std::endl;
        if (caches.find(c) == std::end(caches))
        {
            ++price;
            caches.insert(c);
        }
    }
    std::cout << price << std::endl;
}

int main() 
{
    int n;
    std::cin >> n;
    for(int i=0; i<n; ++i)
    {
        Solve();    
    }
    return 0;
}
