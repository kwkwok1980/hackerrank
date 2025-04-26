void miniMaxSum(vector<int> arr) {
    long sum = 0;
    int min  = std::numeric_limits<int>::max();
    int max  = std::numeric_limits<int>::min();
    for (int i=0; i<5; ++i) {
        sum = sum + arr[i];
        min = std::min(min, arr[i]);
        max = std::max(max, arr[i]);
    }    
    std::cout << sum - max << " " << sum - min << std::endl;
}
