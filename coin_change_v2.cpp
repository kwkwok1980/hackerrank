// https://www.hackerrank.com/challenges/coin-change/problem

long getWays(int N, std::vector<long> coins) {
    int M = coins.size();
    long results[250+1][50+1]{};
    for (int n=0; n<=N; ++n) {
        for (int m=0; m<M; ++m) {
            long coin = coins[m];
            long result = 0;
            if (m == 0) {
                if (coin == n) {
                    result = 1;
                } else if (n > coin) {
                    result = result + results[n-coin][m];
                }
            } else {
                result = results[n][m-1];
                if (n == coin) {
                    result = result + 1;
                } else if (n > coin) {
                    result = result + results[n-coin][m];
                }
            }
            results[n][m] = result;
        }
    }
    return results[N][M-1];
}
