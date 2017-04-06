#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <limits> 
#include <map>
#include <set>

auto LongestCommonSuffix2(const std::string& s)
{
    int n = s.length();
    std::map<int, std::set<int>> map;
    for (int i=0; i<n; ++i)
    {
        map[s[i]].insert(i);    
    }
    
    std::vector<int> lens(n);
    for(int i=0; i<n; ++i)
    {
        int max = 0;
        for(int j : map[s[i]])
        {
            if (j==i) break;
            int l =0;
            for(int k=0; k<n; ++k)
            {
                if (j+k<i && i+k<n && s[j+k] == s[i+k])
                {
                    ++l;
                }
                else
                {
                    break;    
                }
            }
            max = std::max(max, l);
        }
        lens[i] = max;
    }
    return lens;
}


void Solve()
{
    std::string s;
    int n, a, b;
    std::cin >> n >> a >> b;
    std::cin >> s;
    //std::cout << n << " " << a << " " << b << " " << s << std::endl;
    
    std::vector<int> len;
    
    len = LongestCommonSuffix2(s);
    /*
    for(int i=0; i<n; ++i)
    {
        std::cout << i << ":" << len2[i] << std::endl;
    }
    std::cout << "---------------" << std::endl;
    */
    
    std::vector<int> results(n);
    for (int i=0; i<n; ++i)
    {
        results[i] = std::numeric_limits<int>::max();    
    }
    
    results[0] = a;
    for (int i=1; i<n; ++i)
    {
        results[i] = std::min(results[i], results[i-1]+a);
        for(int j=0; j<len[i]; ++j)
        {
            results[i+j] = std::min(results[i+j], results[i-1]+b);
        }
    }
    
    /*
    for(int i=0; i<n; ++i)
    {
        std::cout << i << "\t" << s[i] << "\t" << len[i] << "\t" << results[i] << std::endl;
    }
    */
    
    std::cout << results[n-1] << std::endl;
}

int main() {
    int t; 
    std::cin >> t;
    
    for(int i=0; i<t; ++i)
    {
        Solve();    
    }
    return 0;
}
