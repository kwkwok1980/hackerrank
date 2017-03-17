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


using namespace std;

int T;
int N;
int A;
int B;
std::string s;

std::map<long, int> grid;
const int size = 30000;
int result[size + 1];

int GetGrid(int i, int j)
{
    long key = i * 100000 + j;
    auto it = grid.find(key);
    if (it != std::end(grid))
    {
        return it->second;    
    }
    else
    {
        return 0;    
    }
}

void SetGrid(int i, int j, int v)
{
    long key = i * 100000 + j;
    grid[key] = v;
}

void PrintGrid()
{
    for(int i=1; i<=N; ++i)
    {
        for (int j=1; j<=N; ++j)
        {
            std::cout << GetGrid(i,j) << " ";
        }
        std::cout << std::endl;
    }
}

int Solve(int p)
{
    if (result[p] != 0)
    {
        //std::cout << p << ":" << result[p] << std::endl;
        return result[p];
    }
    
    if (p == 1)
    {
        //std::cout << p << ":" << A << std::endl;
        result[p] = A;
        return A;
    }
    
    int score = Solve(p-1) + A;
    int min = score;
    for(int j=1; j<p; ++j)
    {
        int v = GetGrid(p,j);
        if (v != 0)
        {
            for(int k=1; k<=v; ++k)
            {
                if(p-k >= j)
                {
                    score = Solve(p-k) + B;
                    min = std::min(min, score);
                }
                else
                {
                   break;    
                }
            }
        }
    }
    
    result[p] = min;
    //std::cout << p << ":" << min << std::endl;
    return min;    
}


void BuildString()
{
    //std::cout << N << "," << A << "," << B<< "," << s << std::endl;
    
    memset(result, 0, (size+1)*sizeof(int)/sizeof(char));
    grid.clear();
    for(int i=0; i<=N; ++i)
    {
        SetGrid(0,i,0);
        SetGrid(i,0,0);
    }
    
    for(int i=1; i<=N; ++i)
    {
        for (int j=i; j<=N; ++j)
        {
            if (s[i-1] == s[j-1])
            {
                int v = GetGrid(i-1,j-1) + 1;
                SetGrid(i,j,v);
                SetGrid(j,i,v);
            }
            else
            {
                SetGrid(i,j,0);
                SetGrid(j,i,0);
            }
        }
    }
    
    int min = Solve(N);
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
