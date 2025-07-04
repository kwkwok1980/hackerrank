// https://www.hackerrank.com/challenges/maximum-element/problem?isFullScreen=true

std::vector<int> getMax(std::vector<std::string> operations) {
    std::map<int, int, std::greater<int>> value_map{};
    std::stack<int> value_stack{};
    std::vector<int> results{};
    for (auto& operation: operations) {
        if (operation[0] == '1') {
            int value = atoi(operation.data() + 2);
            ++value_map[value];
            value_stack.push(value);
        } else if (operation[0] == '2') {
            int value = value_stack.top();
            value_stack.pop();
            --value_map[value];
            if (value_map[value] == 0) {
                value_map.erase(value);
            }
        } else if (operation[0] == '3') {
            results.emplace_back(value_map.begin()->first);
        }
    }
    return results;
}
