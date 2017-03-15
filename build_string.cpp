#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <string.h>

using namespace std;

template<typename T>
void Print(T t)
{
    std:cout << t << std::endl;
}

const int size = 10000;
int grid[size][size];

void PrintGrid(int N)
{
    for(int i=1; i<=N; ++i)
    {
        for (int j=1; j<=N; ++j)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void BuildString(int N, int A, int B, std::string s)
{
    if (N > size-1)
    {
        return;    
    }
    
    //std::cout << N << "," << A << "," << B<< "," << s << std::endl;
    memset(grid, 0, size*size*sizeof(int));
    for(int i=1; i<=N; ++i)
    {
        for (int j=i; j<=N; ++j)
        {
            if (s[i-1] == s[j-1])
            {
                grid[i][j] = grid[i-1][j-1] + 1;
                grid[j][i] = grid[i][j];
                
            }
            else
            {
                grid[i][j] = 0;
                grid[j][i] = 0;
            }
        }
    }
    
    //PrintGrid(N);
    
    int length = 0 ;
    int cost = 0;
    for (int i=N; i>=1; --i)
    {
        if (N - i >= length)
        {
            //std::cout << "i:" << i << std::endl;
            int max = 0;
            int J = i;
            for(int j=i-1; j>=1; --j)
            {
                int v = grid[i][j];
                //std::cout << "v:" << i << "," << j << ", " << v << std::endl;                
                if (v !=0)
                {
                    if (i-j >= v)
                    {
                        if (v>max)
                        {
                            max = v;
                            J = j;
                        }
                    }
                }
            }
            
            if (max == 0)
            {
                length = length + 1;    
                cost = cost + A;
                //std::cout << s[J-1] << "," << cost << std::endl;
            }
            else
            {
                if (B < A * max)
                {
                    length = length + max;
                    cost = cost + B;
                    
                    /*
                    for(int k=max; k>0; --k)
                    {
                        std::cout << s[J-k];
                    }
                    std::cout << "," << cost << std::endl;    
                    */
                }
                else
                {
                    length = length + 1;    
                    cost = cost + A;
                    //std::cout << s[J-1] << "," << cost << std::endl;
                    
                }
            }
        }
    }
    
    std::cout << cost << std::endl;
    
    
}

int main() {
    std::string s;
    
    std::getline(std::cin, s);
    int T = atoi(s.c_str());
    
    for(int i=0; i<T; ++i)
    {
        std::getline(std::cin, s);
        std::stringstream ss {s};
        std::getline(ss, s, ' ');
        int N = atoi(s.c_str());
        
        std::getline(ss, s, ' ');
        int A = atoi(s.c_str());
        
        std::getline(ss, s, ' ');
        int B = atoi(s.c_str());
        
        std::getline(std::cin, s);
        BuildString(N, A, B, s);
    }
    return 0;
}
