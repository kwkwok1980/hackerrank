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
    
    bool operator>=(const Count& count)
    {
        return A>=count.A && C>=count.C && G>=count.G && T>=count.T;
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
    
    if (Count{0,0,0,0} >= target)
    {
        std::cout << 0 << std::endl;    
        return 0;
    }
    
    //target.Print();
    int min = size;
    
    Count count;
    int end = 0;
    char c = 0;
    int t = 0;
    int v = 0;
    
    for (int i=0; i<size; ++i)
    {
        //std::cout << "------------------" << std::endl;
        if (i==end)
        {
            count = Count{0,0,0,0};
            end = i+1;
            c = s[i];
            t = target.Get(c);
            if (t != 0)
            {
                count.Add(c, 1);    
            }
        }
        else
        {
            c = s[i-1];
            t = target.Get(c);
            if (t != 0)
            {
                count.Add(c,-1);    
            }
        }
        
        //std::cout << "CP2:" << i << "," << end << std::endl;
        //count.Print();
        
        if (count >= target)
        {
            min = std::min(min,end-i);
            continue;    
        }
        
        for (int j=end; j<size; ++j)
        {
            c = s[j];
            t = target.Get(c);
            if (t == 0)
            {
                ++end;
            }
            else
            {
                v = count.Get(c);
                ++end;
                count.Add(c,1);
                if (count >= target)
                {
                    min = std::min(min,end-i);
                    break;    
                }
            }
        }
        
        //std::cout << "CP3:" << i << "," << end << std::endl;
        //count.Print();
        
        if (end == size)
        {
            break;    
        }
        
    }
    
    std::cout << min << std::endl;
    
    return 0;
}
