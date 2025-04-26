void plusMinus(vector<int> arr) {
    int p = 0, n=0, z = 0;
    for (int value : arr) {
        if (value < 0) {
            ++n;
        } else if (value > 0) {
            ++p;
        } else {
            ++z;
        }
    }
    std::cout << static_cast<double>(p) / arr.size() << std::endl;
    std::cout << static_cast<double>(n) / arr.size() << std::endl;
    std::cout << static_cast<double>(z) / arr.size() << std::endl;
}
