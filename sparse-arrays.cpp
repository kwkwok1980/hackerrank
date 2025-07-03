// https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true
std::vector<int> matchingStrings(std::vector<std::string> stringList, std::vector<std::string> queries) {
    std::unordered_map<std::string, std::size_t> cache_map{};
    for (const auto& s : stringList) {
        ++cache_map[s];
    }
    std::vector<int> results(queries.size(), 0);
    for (int i=0; i<queries.size(); ++i) {
        results[i] = cache_map[queries[i]];
    }
    return results;
}
