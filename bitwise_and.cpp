#include <iostream>
#include <vector>
#include <bit>

int bitwise_and(const std::vector<int>& values) {
    int count = 0;
    for (int i=0; i<values.size()-1; ++i) {
        for (int j=i+1; j<values.size(); ++j) {
            unsigned value = values[i] & values[j];
            if (std::has_single_bit(value)) {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    std::vector<int> values {10, 7, 2, 4, 3};
    std::cout << bitwise_and(values) << std::endl;
}
