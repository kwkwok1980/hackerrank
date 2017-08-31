#include <math.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>

std::unordered_map<int, long double> Tens;


long double Solve1(int n)
{
    auto itFind = Tens.find(n);
    if (itFind != Tens.end())
    {
        long double r = itFind->second;
        std::cout << "Solve 1 " << n << " " << r << std::endl;
        return r;
    }

    if(n%2 == 0)
    {
        int h = n/2;
        long double r = Solve1(h) * Solve1(h);
        std::cout << "Solve 2 " << n << " " << r << std::endl;
        Tens[n] = r;
        return r;
    }
    else
    {
        int h = n/2;
        long double r = Solve1(h) * Solve1(h) * 10;
        std::cout << "Solve 3 " << n << " " << r << std::endl;
        Tens[n] = r;
        return r;
    }
}

long double Solve2(int n)
{
    std::deque<int> queues;
    while(true)
    {
        if (n <= 10)
        {
            queues.emplace_back(n);
            break;
        }
        else
        {
            if (n%2 == 0)
            {
                int h = n/2;
                queues.emplace_back(h);
                n = h;
            }
            else
            {
                int h = n/2;
                queues.emplace_back(h);
                queues.emplace_back(1);
                n = h;
            }
        }
    }

    long double r = 1;
    int index = 0;

    while(queues.empty() == false)
    {
        int value = queues.back();
        queues.pop_back();
        index = index + value;
        r = r * Tens[value];
        Tens[index] = r;

        std::cout << "Halo " << value << " " << index << " " << r << std::endl;
    }

    return r;


}

int main()
{
    Tens[0] = 1;
    Tens[1] = 10;
    Tens[2] = 100;
    Tens[3] = 1000;
    Tens[4] = 10000;
    Tens[5] = 100000;
    Tens[6] = 1000000;
    Tens[7] = 10000000;
    Tens[8] = 100000000;
    Tens[9] = 1000000000;
    Tens[10] = 10000000000;

    long double r = Solve2(100);

    std::cout << "Halo " << r << std::endl;
}
