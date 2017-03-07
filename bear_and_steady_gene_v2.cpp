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
    
    Count operator-(int i)
    {
        return Count{A-i,C-i,G-i,T-i};
    }
    
    Count operator+(int i)
    {
        return Count{A+i,C+i,G+i,T+i};
    }
    
    Count operator+(const Count& c)
    {
        return Count{A+c.A,C+c.C,G+c.G,T+c.T};
    }
    
    int Length()
    {
        return std::max(A,0) + std::max(C,0) + std::max(G,0) + std::max(T,0);
    }
    
    bool Zero()
    {
        return A==0 && C==0 && G==0 && T==0;    
    }
    
    bool Match(const Count& c)
    {
        if(A>0 && A!=c.A) return false;
        if(C>0 && C!=c.C) return false;
        if(G>0 && G!=c.G) return false;
        if(T>0 && T!=c.T) return false;
        return true;
    }
    
    void Print()
    {
        std::cout << A << "," << C << "," << G << "," << T << std::endl;
    }
        
};

Count result [2][500000];

Count GetCount(const std::string& s)
{
    Count count {0,0,0,0};
    for (auto& c : s)
    {
        if (c == 'A') ++count.A;
        else if (c == 'C') ++count.C;
        else if (c == 'G') ++count.G;
        else ++count.T;
    }
    return count;
}

int main() 
{
    std::string s;
    
    std::getline(std::cin, s);
    int size = atoi(s.c_str());
    int div = size / 4;
    //std::cout << div << std::endl;
    
    std::getline(std::cin, s);
    //std::cout << s << std::endl;

    Count count = GetCount(s);
    count = count - div;
    //count.Print();
    int min = count.Length();
    
    int y1 = 0;
    int y2 = 1;
    
    for (int n=min; n<=size; ++n)
    {
        for(int i=0; i<size-n; ++i)
        {
            if(n==min)
            {
                std::string s1 = s.substr(i, n);
                result[y2][i] = GetCount(s1);
            }
            else
            {
                char c = s[i+n-1];
                result[y2][i] = result[y1][i];
                if (c == 'A') ++result[y2][i].A;
                else if (c == 'C') ++result[y2][i].C;
                else if (c == 'G') ++result[y2][i].G;
                else ++result[y2][i].T;
            }
            
            if (count.Match(result[y2][i]))
            {
                //std::string s1 = s.substr(i, n);
                //std::cout << s1 << std::endl;
                std::cout << n << std::endl;
                return 0;
            }
        }
        
        y1 = (y1==0) ? 1 : 0;
        y2 = (y2==0) ? 1 : 0;
    }
    
    
    return 0;
}
