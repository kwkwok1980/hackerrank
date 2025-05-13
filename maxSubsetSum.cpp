int maxSubsetSum(std::vector<int> values) {
    int N = values.size();
    std::vector<int> results(N, 0);
    for (int i=0; i<N; ++i) {
        int value = values[i];
        if (i == 0) {
            results[0] = std::max(0, value);
        } else if(i == 1) {
            results[1] = std::max(value, results[0]);
        } else {
            results[i] = std::max(results[i-2] + value, results[i-1]);
        }
    }
    return results[N-1];
}
