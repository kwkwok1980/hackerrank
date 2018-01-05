#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>

std::int64_t results [250+1];

void Solve(int N, int M, const std::vector<int>& coins)
{
    results[0] = 1;
    for(int m=0; m<M; ++m)
    {
        for(int n=1; n<=N; ++n)
        {
            if (n >= coins[m])
            {
                results[n] = results[n] + results[n-coins[m]];
            }
        }

    }
    std::cout << results[N] << std::endl;
}

int main()
{
    int N, M;
    std::cin >> N;
    std::cin >> M;

    std::vector<int> values;
    for(int m=0; m<M; ++m)
    {
        int value;
        std::cin >> value;
        values.push_back(value);
    }

    Solve(N, M, values);
    return 0;
}
