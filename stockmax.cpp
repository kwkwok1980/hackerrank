// https://www.hackerrank.com/challenges/stockmax/problem?isFullScreen=true

long stockmax(vector<int> prices) {
    int N = prices.size();
    std::vector<int> max_prices(N, 0);
    max_prices[N-1] = prices[N-1];
    for (int i=N-2; i>=0; --i) {
        max_prices[i] = std::max(prices[i], max_prices[i+1]);
    }
    
    long profit = 0;
    for (int i=0; i<N; ++i) {
        profit = profit + std::max(0, (max_prices[i] - prices[i]));
    }
    return profit;
}
