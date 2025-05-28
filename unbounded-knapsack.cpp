// https://www.hackerrank.com/challenges/unbounded-knapsack/problem?isFullScreen=true

std::vector<int> results(2000 + 1, 0);

int unboundedKnapsackImpl(int k, std::vector<int>& values) {
    int result = results[k];
    if (result != -1) {
        return result;
    }
    if (k == 0) {
        return 0;
    }
    result = k;
    for (int value : values) {
        if (k >= value) {
            int r = k - value;
            result = std::min(result, unboundedKnapsackImpl(r, values));
        }
    }
    return results[k] = result;
}


int unboundedKnapsack(int k, std::vector<int> values) {
    std::fill(results.begin(), results.end(), -1);
    return k - unboundedKnapsackImpl(k, values);
}
