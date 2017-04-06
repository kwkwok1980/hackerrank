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
        /*
        std::cout << "--- rank ----" << std::endl;
        for (int i=0; i<n; ++i)
        {
            std::cout << i << ":" << rank[i] << std::endl;
        }
        */
        
        auto func = [&](int i, int j)
        {
            auto pair1 = std::make_pair(rank[i], (i+k) < n ? rank[i+k] : -1);
            auto pair2 = std::make_pair(rank[j], (j+k) < n ? rank[j+k] : -1);
            return pair1 < pair2;
        };
        std::sort(sa.begin(), sa.end(), func);
        
        /*
        std::cout << "--- sa ----" << std::endl;
        for(auto& i : sa) 
        {
            std::cout << i << ":";
            for(int j=i; j<n; ++j)
            {
                std::cout << s[j];
            }
            std::cout << std::endl;
        }
        */
        
        std::vector<int> dp(n);
        for (int i=0; i<n; ++i)
        {
            if (i==0)
            {
                dp[sa[i]] = 0; 
                //std::cout << "--- r0 ----" << sa[i] << ":" << dp[sa[i]] << std::endl;
            }
            else 
            {
                if (func(sa[i-1], sa[i]))
                {
                    dp[sa[i]] = dp[sa[i-1]] + 1;
                    //std::cout << "--- r1 ----" << sa[i] << ":" << dp[sa[i]] << std::endl;
                }
                else
                {
                    dp[sa[i]] = dp[sa[i-1]];
                    //std::cout << "--- r2 ----" << sa[i] << ":" << dp[sa[i]] << std::endl;
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
            if (sa[j] > i)
            {
               continue;    
            }
            else
            {
                int l = 0;
                for(int k=0; k<n; ++k)
                {
                    if (i+k<n && sa[j]+k<n)
                    {
                        if (s[i+k] == s[sa[j]+k])
                        {
                            ++l;    
                        }
                        else
                        {
                            break;    
                        }
                    }
                    else
                    {
                        break;    
                    }
                }
                maxlen = std::max(maxlen, l);
                break;
            }
        }
        
        for(int j=rank[i]+1; j<n; ++j)
        {
            if (sa[j] > i)
            {
               continue;    
            }
            else
            {
                int l = 0;
                for(int k=0; k<n; ++k)
                {
                    if (i+k<n && sa[j]+k<i)
                    {
                        if (s[i+k] == s[sa[j]+k])
                        {
                            ++l;
                        }
                        else
                        {
                            break;    
                        }
                    }
                    else
                    {
                        break;    
                    }
                }
                maxlen = std::max(maxlen, l);
                break;
            }
        }
        
        len[i] = maxlen;
    }
    
    return len;
}


void Solve()
{
    std::string s;
    int n, a, b;
    std::cin >> n >> a >> b;
    std::cin >> s;
    //std::cout << n << " " << a << " " << b << " " << s << std::endl;
    
    std::vector<int> sa, rank, len;
    std::tie(sa, rank) = SuffixArray(s);
    
    /*
    for(auto& i : sa) 
    {
        std::cout << i << ":";
        for(int j=i; j<n; ++j)
        {
            std::cout << s[j];
        }
        std::cout << std::endl;
    }
    */
    
    len = LongestCommonSuffix(s);
    
    /*
    std::cout << "---------------" << std::endl;
    for(int i=0; i<n; ++i)
    {
        std::cout << i << ":" << len[i] << std::endl;
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
        std::cout << results[i] << std::endl;
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
