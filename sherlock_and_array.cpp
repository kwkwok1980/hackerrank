#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

void Solve(const std::vector<int>& values)
{
    int leftSum = 0;
    int rightSum = std::accumulate(values.begin()+1, values.end(), 0);
    auto it = values.begin();
    while(it != values.end())
    {
        if (leftSum == rightSum)
        {
            std::cout << "YES" << std::endl;
            return;
        }
        leftSum = leftSum + *it;
        ++it;
        if (it != values.end())
        {
            rightSum = rightSum - *it;    
        }
    }
    std::cout << "NO" << std::endl;
}


int main() 
{
    int T;
    std::cin >> T;
    for (int i=0; i<T; ++i)
    {
        int A;
        std::cin >> A;
        std::vector<int> values;
        for (int j=0; j<A; ++j)
        {
            int value;
            std::cin >> value;
            values.emplace_back(value);
        }
        Solve(values);
    }
    return 0;
}
