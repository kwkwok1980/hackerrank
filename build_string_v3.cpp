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

std::map<long, int> grid;
const int size = 30000;
int result[size + 1];
int value[size+1];

int GetGrid(int i, int j)
{
    long key = i * 100000 + j;
    if(grid.find(key) == std::end(grid))
    {
        return 0;        
    }
    return grid[key];
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
        }
    }
    
    for(int i=1; i<=N; ++i)
    {
        int max =0 ;
        for (int j=1; j<i; ++j)
        {
            int v = GetGrid(i,j);
            if (v != 0)
            {
                if (i-v < j)
                {
                    v = i-j;    
                }
                max = std::max(max,v);
            }
        }
        value[i] = max;
    }
    
    //PrintGrid();
    //std::cout << "---------" << std::endl;
    
    for(int i=1; i<N; ++i)
    {
        //Solve(i);
        //std::cout << "---------" << std::endl;
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
