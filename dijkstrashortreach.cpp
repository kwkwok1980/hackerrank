// https://www.hackerrank.com/challenges/dijkstrashortreach/problem

std::vector<int> shortestReach(int n, std::vector<std::vector<int>> edges, int s) {
    std::unordered_map<int, std::unordered_map<int, int>> graphs{};
    for (std::vector<int>& edge : edges) {
        int i = edge[0];
        int j = edge[1];
        int d = edge[2];
        {
            auto& graph = graphs[i];
            if (graph.find(j) == graph.end()) {
                graph[j] = d;
            } else {
                if (graph[j] > d) {
                    graph[j] = d;
                }
            }
        }
        {
            auto& graph = graphs[j];
            if (graph.find(i) == graph.end()) {
                graph[i] = d;
            } else {
                if (graph[i] > d) {
                    graph[i] = d;
                }
            }
        }
    }

    std::vector<int> distances(n+1, -1);
    std::deque<int> visits{};
    distances[s] = 0;
    visits.emplace_back(s);

    while(!visits.empty()){
        int i = visits.front();
        visits.pop_front();
        for (auto [j, d] : graphs[i]) {
            if (distances[i] + d < distances[j] || distances[j] == -1) {
                distances[j] = distances[i] + d;
                visits.emplace_back(j);
            }
        }
    }

    std::vector<int> results{};
    for (int i=1; i<=n; ++i) {
        if (i != s) {
            results.emplace_back(distances[i]);
        }
    }
    return results;
}
