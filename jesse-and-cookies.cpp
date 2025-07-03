// https://www.hackerrank.com/challenges/jesse-and-cookies/problem?isFullScreen=true

int cookies(int K, std::vector<int> values) {
    std::map<int, int> value_map{};
    for (auto value : values) {
        ++value_map[value];
    }
    int count = 0;
    while (true) {
        auto it_1 = value_map.begin();
        int value_1 = it_1->first;
        int count_1 = it_1->second;
        if (value_1 >= K) {
            return count;
        }
        if (value_map.size() == 1) {
            if (count_1 == 1) {
                return -1;    
            }            
        }
        if (count_1 == 1){
            value_map.erase(it_1);
            auto it_2 = value_map.begin();
            int value_2 = it_2->first;
            int count_2 = it_2->second;
            if (count_2 == 1){
                value_map.erase(it_2);
            } else {
                it_2->second = count_2 - 1;
            }
            int value = value_1 + 2 * value_2;
            ++value_map[value];
        } else {
            if (count_1 == 2){
                value_map.erase(it_1);
            } else {
                it_1->second = count_1 - 2;    
            }
            int value = value_1 + 2 * value_1;
            ++value_map[value];
        }
        ++count;
    }
    return -1;
}

int cookies_bkp(int K, std::vector<int> values) {
    std::sort(values.begin(), values.end(), std::greater<>{});
    int count = 0;
    while (true) {
        if (values.back() >= K) {
            return count;
        }
        if (values.size() == 1) {
            return -1;
        }
        int value1 = values.back();
        values.pop_back();
        int value2 = values.back();
        values.pop_back();
        int value3 = value1 + 2 * value2;
        auto it = std::upper_bound(values.begin(), values.end(), value3, std::greater<>{});
        values.insert(it, value3);
        ++count;
    }
    return -1;
}
