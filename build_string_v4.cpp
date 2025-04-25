#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <map>
#include <set>


using namespace std;

int T;
int N;
int A;
int B;
std::string s;

const int size = 30000;
int result[size + 1];
int value[size+1];

int Solve(int p)
{
    if (result[p] != 0)
    {
        //std::cout << p << ":cp1 " << result[p] << std::endl;
        return result[p];
    }
    
    if (p == 1)
    {
        //std::cout << p << ":cp2 " << A << std::endl;
        result[p] = A;
        return A;
    }
    
    int score = Solve(p-1) + A;
    int min = score;
    
    int maxv = value[p];
    if (maxv !=0)
    {
        for(int i=1; i<=maxv; ++i)
        {
            score = Solve(p-i) + B;
            min = std::min(min, score);    
        }
    }
    
    result[p] = min;
    //std::cout << p << ":cp0 " << min << std::endl;
    return min;    
}


void BuildString()
{
    //std::cout << N << "," << A << "," << B<< "," << s << std::endl;
    
    int grid2[2][size+1];
    memset(grid2, 0, 2*(size+1)*sizeof(int));
    memset(result, 0, (size+1)*sizeof(int));
    
    int index0 = 0;
    int index1 = 1;
    for(int i=1; i<=N; ++i)
    {
        int max =0 ;
        for (int j=1; j<=N; ++j)
        {
            if (s[i-1] == s[j-1])
            {
                int v = grid2[index0][j-1] + 1;
                grid2[index1][j] = v;
                if (j<i)
                {
                    if (i-v < j)
                    {
                        v = i-j;    
                    }
                    max = std::max(max,v);    
                }
            }
        }
        
        value[i] = max;
        
        if (index0 == 0)
        {
            index0 = 1;
            index1 = 0;
        }
        else
        {
            index0 = 0;
            index1 = 1;
        }
        memset(grid2[index1], 0, (size+1)*sizeof(int));        
    }
    
    int min = 0;
    min = Solve(N);
    std::cout << min << std::endl;
}

int main() 
{
    std::string line;
    std::getline(std::cin, line);
    T = atoi(line.c_str());
    
    for(int i=0; i<T; ++i)
    {
        std::getline(std::cin, line);
        std::stringstream ss {line};
        std::getline(ss, line, ' ');
        N = atoi(line.c_str());
        
        std::getline(ss, line, ' ');
        A = atoi(line.c_str());
        
        std::getline(ss, line, ' ');
        B = atoi(line.c_str());
        
        std::getline(std::cin, s);
        BuildString();
    }
    return 0;
}
