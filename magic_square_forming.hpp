#include <iostream>
#include <vector>
#include <array>
#include <bit>
#include <unordered_map>
#include <cmath>
#include <string_view>
#include <fstream>
#include <ranges>
#include <algorithm>
#include <unordered_set>

int forming_magic_square(std::vector<std::vector<int>> s) {
    std::vector<std::vector<int>> results{};
    results.push_back({8, 3, 4, 1, 5, 9, 6, 7, 2});
    results.push_back({6, 7, 2, 1, 5, 9, 8, 3, 4});
    results.push_back({6, 1, 8, 7, 5, 3, 2, 9, 4});
    results.push_back({8, 1, 6, 3, 5, 7, 4, 9, 2});
    results.push_back({2, 7, 6, 9, 5, 1, 4, 3, 8});
    results.push_back({4, 3, 8, 9, 5, 1, 2, 7, 6});
    results.push_back({4, 9, 2, 3, 5, 7, 8, 1, 6});
    results.push_back({2, 9, 4, 7, 5, 3, 6, 1, 8});

    std::vector<int> inputs{};
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            inputs.push_back(s[i][j]);
        }
    }

    int min = std::numeric_limits<int>::max();
    for (int i=0; i<8; ++i) {
        int sum = 0;
        for (int j=0; j<9; ++j) {
            sum = sum + abs(inputs[j] - results[i][j]);
        }
        min = std::min(min, sum);
    }

    return min;
}