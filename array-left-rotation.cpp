// https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true

std::vector<int> rotateLeft(int d, std::vector<int> arr) {
    std::size_t N = arr.size();
    std::vector<int> results(N, 0);
    std::memcpy(results.data(), arr.data() + d, (N-d) * sizeof(int));
    std::memcpy(results.data()+N-d, arr.data(), d * sizeof(int));
    return results;
}
