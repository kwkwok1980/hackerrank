#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Count
{
    int A;
    int C;
    int G;
    int T;
    
    void Print()
    {
        std::cout << A << "," << C << "," << G << "," << T << std::endl;
    }
    
    void Set(char c, int i)
    {
        switch(c)
        {
            case 'A': A=i; break;
            case 'C': C=i; break;
            case 'G': G=i; break;
            default: T=i; break;
        }
    }
    
    int Get(char c)
    {
        switch(c)
        {
            case 'A': return A;
            case 'C': return C;
            case 'G': return G;
            default: return T;
        }
    }
    
    void Add(char c, int i)
    {
        switch(c)
        {
            case 'A': A=A+i; break;
            case 'C': C=C+i; break;
            case 'G': G=G+i; break;
            default: T=T+i; break;
        }
    }
     
    bool operator==(const Count& count)
    {
        return A==count.A && C==count.C && G==count.G && T==count.T;
    }
        
};

int main() 
{
    std::string s;
    char genes[4] = {'A','C','G','T'}; 
    
    std::getline(std::cin, s);
    int size = atoi(s.c_str());
    
    std::getline(std::cin, s);
    int div = size/4;
    
    Count target{-div,-div,-div,-div};
    for (int i=0; i<size; ++i)
    {
        target.Add(s[i],1);
    }
    
    for(char gene : genes)
    {
        if (target.Get(gene) < 0)
        {
            target.Set(gene, 0);    
        }
    }
    
    //target.Print();
    int min = size;
    
    Count count {0,0,0,0};
    int begin = 0;
    int end = 4;
    
    for(int i=0; i<4; ++i)
    {
        char c = s[i];
        if (target.Get(c) != 0)
        {
            count.Add(c,1);    
        }
    }
    
    while(end < size)
    {
        if (count == target)
        {
                
        }
    }
    
    
    for (int i=0; i<size; ++i)
    {
        Count count {0,0,0,0};
        for (int j=i; j<size; ++j)
        {
            char c = s[j];
            if (target.Get(c) > 0)
            {
                count.Add(c, 1);
                if (count.Get(c) > target.Get(c))
                {
                    break;    
                }
                
                if (count == target)
                {
                    int len = j-i+1;
                    min = std::min(min, len);
                    break;
                }
            }
        }
    }
    
    std::cout << min << std::endl;
    
    return 0;
}
