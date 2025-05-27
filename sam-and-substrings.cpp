// https://www.hackerrank.com/challenges/sam-and-substrings/problem?isFullScreen=true
constexpr int M = 1000000000 + 7;

long substrings(std::string s) {
    int N = s.size();
    std::vector<int> values(N, 0);
    for (int i=0; i<N; ++i) {
        values[i] = atoi(s.substr(i, 1).c_str());
    }
    std::vector<long> multipliers(N, 1);
    for (int i=N-2; i>=0; --i) {
        multipliers[i] = (multipliers[i+1] * 10 + 1) % M;
    }
    std::vector<long> results(N, 0);
    results[N-1] = values[N-1];
    for (int i=N-2; i>=0; --i) {
        results[i] = (multipliers[i] * values[i] %M + results[i+1]) % M;
    }
    long sum = 0;
    for (int i=0; i<N; ++i) {
        sum = (sum + results[i]) % M;
    }
    return sum;
}
