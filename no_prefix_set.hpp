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

void no_prefix_set(std::vector<std::string> words) {
    std::unordered_set<std::string_view> keys1{};
    std::unordered_set<std::string_view> keys2{};
    for (std::string& word : words) {
        if (keys2.find(word) != keys2.end()) {
            std::cout << "BAD SET" << std::endl;
            std::cout << word << std::endl;
            return;
        }
        for (std::size_t i=0; i<word.size(); ++i) {
            std::string_view key {word.data(), i+1};
            if (keys1.find(key) != keys1.end()) {
                std::cout << "BAD SET" << std::endl;
                std::cout << word << std::endl;
                return;
            }
            keys2.emplace(key);
        }
        keys1.emplace(word);
    }
    std::cout << "GOOD SET" << std::endl;
}

void test(std::string_view input) {
    std::cout << input << std::endl;
    std::ifstream ifs{input.data()};
    int N;
    ifs >> N;
    std::vector<std::string> values(N, "");
    for (int i=0; i<N; ++i) {
        ifs >> values[i];
    }
    no_prefix_set(values);
    std::cout << "=======================================" << std::endl;
}

int main() {
    test("/tmp/temp.txt");
    return EXIT_SUCCESS;
}
