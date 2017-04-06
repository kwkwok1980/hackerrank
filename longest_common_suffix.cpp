#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <limits> 

auto SuffixArray(const std::string& s)
{
    int n = s.length();
    std::vector<int> sa(n);
    std::vector<int> rank(n);
    
    for(int i=0; i<n; ++i)
    {
        sa[i] = i;
        rank[i] = s[i];
    }
    
    for(int k=1; k<n; k=k*2)
    {
        auto func = [&](int i, int j)
        {
            auto pair1 = std::make_pair(rank[i], (i+k) < n ? rank[i+k] : -1);
            auto pair2 = std::make_pair(rank[j], (j+k) < n ? rank[j+k] : -1);
            return pair1 < pair2;
        };
        std::sort(sa.begin(), sa.end(), func);
        
        std::vector<int> dp(n);
        for (int i=0; i<n; ++i)
        {
            if (i==0)
            {
                dp[sa[i]] = 0; 
            }
            else 
            {
                if (func(sa[i-1], sa[i]))
                {
                    dp[sa[i]] = dp[sa[i-1]] + 1;
                }
                else
                {
                    dp[sa[i]] = dp[sa[i-1]];
                }
            }
            
        }
        rank = std::move(dp);
    }
    return std::make_pair(sa, rank);
}


auto LongestCommonSuffix(const std::string& s)
{
    int n = s.length();
    std::vector<int> sa, rank, len(n);
    std::tie(sa, rank) = SuffixArray(s);
    
    for(int i=0; i<n; ++i)
    {
        int maxlen = 0;
        for(int j=rank[i]-1; j>=0; --j)
        {
            if (sa[j] > i) continue;
            if (s[sa[j]] != s[i]) break;
            
            int l = 0;
            for(int k=0; k<n; ++k)
            {
                if (i+k<n && sa[j]+k<i && s[i+k] == s[sa[j]+k])
                {
                    ++l;
                }
                else
                {
                    break;    
                }
            }
            maxlen = std::max(maxlen, l);
            if (sa[j]+l < i)
            {
                break;    
            }
        }
        
        for(int j=rank[i]+1; j<n; ++j)
        {
            if (sa[j] > i) continue;
            if (s[sa[j]] != s[i]) break;
            int l = 0;
            for(int k=0; k<n; ++k)
            {
                if (sa[j]+k<i && i+k<n && s[sa[j]+k] == s[i+k])
                {
                    ++l;
                }
                else
                {
                    break;    
                }
            }
            maxlen = std::max(maxlen, l);
            if (sa[j]+l < i)
            {
                break;    
            }
        }
        
        len[i] = maxlen;
    }
    
    return len;
}



int main() {
    std::string s = "aabaacaba";
    int n = s.length();
    std::vector<int> sa, rank, len;
    std::tie(sa, rank) = SuffixArray(s);
    
    for(auto& i : sa) 
    {
        std::cout << i << ":";
        for(int j=i; j<n; ++j)
        {
            std::cout << s[j];
        }
        std::cout << std::endl;
    }
    
    len = LongestCommonSuffix(s);
    
    std::cout << "---------------" << std::endl;
    
    for(int i=0; i<n; ++i)
    {
        std::cout << i << ":" << len[i] << std::endl;
    }
    
    
    return 0;
}
