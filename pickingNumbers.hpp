int pickingNumbers(std::vector<int> values) {
    std::vector<int> results(102, 0);
    for (int value : values) {
        ++results[value];
    }
    int max = 0;
    for (int i=1; i<=100; ++i) {
        max = std::max(max, results[i] + results[i+1]);
    }
    return max;
}
