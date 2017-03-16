#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <unordered_set>

using namespace std;

int grid [26][1000];
int counts [26];

void PrintGrid(int N)
{
    for(int i=0; i<26; ++i)
    {
        for (int j=0; j<N; ++j)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


int main() {
    std::string s;
    
    std::getline(std::cin, s);
    int N = atoi(s.c_str());
    
    std::getline(std::cin, s);
    
    //std::cout << N << std::endl;
    //std::cout << s << std::endl;
   
    memset(grid, 0, 26*26*sizeof(int)/sizeof(char));
    memset(counts, 0, 26*sizeof(int)/sizeof(char));
    
    unordered_set<int> values;
    for(int i=0; i<N; ++i)
    {
        int index = s[i]-'a';
        grid[index][i] = 1;
        ++counts[index];
        values.insert(s[i]);
    }
    //PrintGrid(N);
    
    int max = 0;
    int size = 0;
    
    for(int i=0; i<26; ++i)
    {
        char c1 = 'a' + i;
        if (values.find(c1) != std::end(values))
        {
            for(int j=i+1; j<26; ++j)
            {
                char c2 = 'a' + j;
                if (values.find(c2) != std::end(values))
                {
                    //std::cout << "----" << c1 << "," << c2 << std::endl;
                    bool ok = true;
                    char s0 = -1;
                    char s1 = -1;
                    for (int k=0; k<N; ++k)
                    {
                        if (grid[c1-'a'][k] == 1)
                        {
                            s1 = c1;
                        }
                        else if (grid[c2-'a'][k] == 1)
                        {
                            s1 = c2;
                        }
                        else
                        {
                            continue;    
                        }
                        
                        if (s0!=-1 && s1!=-1)
                        {
                            //std::cout << s0 << "," << s1 << std::endl;
                            if (s0 == s1)
                            {
                               ok = false;
                               break; 
                            }    
                        }
                        
                        s0 = s1;
                    }
                    
                    if (ok)
                    {
                        //std::cout << c1 << "," << c2 << "," << counts[c1-'a'] + counts[c2-'a'] << std::endl;
                        max = std::max(max, counts[c1-'a'] + counts[c2-'a']);
                    }
                }
            }
            
            
        }
        
    }
    
    std::cout << max << std::endl;
    
    return 0;
}
