long candies(int n, std::vector<int> values) {
    std::vector<long> results(n, 1);
    for (int i=1; i<n; ++i) {
        if (values[i] > values[i-1]) {
            results[i] = results[i-1] + 1;
        }
    }
    for (int i=n-2; i>=0; --i) {
        if (values[i] > values[i+1]) {
            results[i] = std::max(results[i], results[i+1] +1);
        }
    }
    return std::accumulate(results.begin(), results.end(), 0LL);
}
