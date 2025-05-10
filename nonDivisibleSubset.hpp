int nonDivisibleSubset(int k, vector<int> s) {
    int N = s.size();
    std::vector<int> results(k, 0);
    for (int i=0; i<N; ++i) {
        ++results[s[i] % k];
    }
    int count = 0;
    for (int i=0; i<k; ++i) {
        int j = (k - i) % k;
        if (i == j) {
            if (results[i] > 0) {
                count = count + 1;    
            }
        } else {
            if (results[i] > results[j]) {
                count = count + results[i];
            }
        }
    }
    return count;
}
