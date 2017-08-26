#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <limits>

struct Value
{
    int i;
    long long p;
};

int Solve(std::vector<Value>& values)
{
    auto func = [](auto&& a, auto&& b) -> bool {return a.p < b.p;};
    std::sort(values.begin(), values.end(), func);

    auto g1b = values.begin();
    auto g1e = g1b + 1;
    while(g1e!=values.end() && g1b->p == g1e->p) ++g1e;

    long long d = std::numeric_limits<long long>::max();
    while(g1e != values.end())
    {
        auto g2b = g1e;
        auto g2e = g2b + 1;
        while(g2e!=values.end() && g2b->p == g2e->p) ++g2e;

        if (g2b->p - g1b->p < d)
        {
            bool find = false;
            for(auto it1=g1b; it1!=g1e; ++it1)
            {
                for(auto it2=g2b; it2!=g2e; ++it2)
                {
                    if (it2->i < it1->i)
                    {
                        //std::cout << "f " << it1->i << " " << it1->p << std::endl;
                        //std::cout << "f " << it2->i << " " << it2->p << std::endl;

                        find = true;
                        break;
                    }
                }
                if (find)
                {
                    break;
                }
            }

            if (find)
            {
                d = g2b->p - g1b->p;
            }
        }

        g1b = g2b;
        g1e = g2e;
    }

    return d;
}


int main() {
    int n;
    std::cin >> n;

    std::vector<Value> values;
    for (int i=0; i<n; ++i)
    {
        long long p;
        std::cin >> p;
        values.emplace_back(Value{i,p});
    }

    for (auto&& value : values)
    {
        //std::cout << value.i << "," << value.p << std::endl;
    }

    long long d = Solve(values);
    std::cout << d << std::endl;
    return 0;
}
