#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> climbingLeaderboard(std::vector<int> ranked, std::vector<int> player) {
    int R = static_cast<int>(ranked.size());
    std::vector<int> sorted{};
    for (int i=0; i<R; ++i) {
        int value = ranked[i];
        if (value != sorted.back()) {
            sorted.push_back(value);
        }
    }
    int N = static_cast<int>(player.size());
    std::vector<int> results{};
    for (int i=0; i<N; ++i) {
        int value = player[i];
        auto it = std::lower_bound(sorted.begin(), sorted.end(), value, std::greater<>{});
        int result = static_cast<int>(std::distance(sorted.begin(), it)) + 1;
        results.push_back(result);
        if (*it != value) {
            sorted.insert(it, value);
        }
    }
    return results;
}

void test(std::vector<int> ranked, std::vector<int> player) {
    std::vector<int> results = climbingLeaderboard(ranked, player);
    for (int result : results) {
        std::cout << result << std::endl;
    }
    std::cout << "===========================================" << std::endl;
}

int main() {
    {
        std::vector<int> ranked = {100, 90, 90, 80};
        std::vector<int> player = {70, 80, 105};
        test(ranked, player);
    }
    {
        std::vector<int> ranked = {100, 90, 90, 80, 75, 60};
        std::vector<int> player = {50, 65, 77, 90, 102};
        test(ranked, player);
    }
    return 0;
}
