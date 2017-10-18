#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

//https://sites.google.com/site/indy256/algo_cpp/hopcroft_karp

const int MAXN1 = 50000;
const int MAXN2 = 50000;
const int MAXM = 150000;

int n1, n2, edges, last[MAXN1], previous[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];

void init(int _n1, int _n2)
{
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}

void addEdge(int u, int v)
{
    head[edges] = v;
    previous[edges] = last[u];
    last[u] = edges++;
}

void bfs()
{
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u)
    {
        if (!used[u])
        {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++)
    {
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = previous[e])
        {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0)
            {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

bool dfs(int u1)
{
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = previous[e])
    {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2))
        {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

int maxMatching()
{
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;)
    {
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
        {
            if (!used[u] && dfs(u))
            {
                ++f;
            }
        }
        if (!f)
        {
            return res;
        }
        res += f;
    }
}

struct Biker
{
    int i;
    int n;
    int m;

    bool operator==(const Biker& other) const
    {
        return n == other.n && m == other.m;
    }
};

using Bikers = std::unordered_set<Biker>;

struct Bike
{
    int i;
    int n;
    int m;

    bool operator==(const Bike& other) const
    {
        return n == other.n && m == other.m;
    }
};

using Bikes = std::unordered_set<Bike>;

struct Distance
{
    Biker biker;
    Bike bike;
    long long d;
};

using Distances = std::vector<Distance>;

namespace std
{
    template<>
    struct hash<Bike>
    {
        size_t operator()(const Bike& bike) const
        {
            static std::hash<int> h;
            return h(bike.n) ^ (h(bike.m) << 1);
        }
    };

    template<>
    struct hash<Biker>
    {
        size_t operator()(const Biker& biker) const
        {
            static std::hash<int> h;
            return h(biker.n) ^ (h(biker.m) << 1);
        }
    };

}

void Solve(const Distances& distances, const std::vector<long long>& times, int K)
{
    int begin = 0;
    int end = static_cast<int>(times.size());

    while (true)
    {
        int mid = (begin + end) / 2;
        long long time = times[mid];

        Distances tempDistances;
        for (auto& distance : distances)
        {
            if (distance.d < time)
            {
                tempDistances.emplace_back(distance);
            }
            else
            {
                break;
            }
        }

        init(250, 250);
        for (auto& distance : tempDistances)
        {
            //cout << "Biker " << distance.biker.i << " Bike" << distance.bike.i << endl;
            addEdge(distance.biker.i, distance.bike.i);
        }

        int k = maxMatching();

        //cout << "Size of maximum matching is " << begin << "," << mid << "," << end << "," << k << "," << time << ","
        //     << tempDistances.size() << endl;
        if (k < K)
        {
            begin = mid;
        }
        else
        {
            end = mid;
        }

        if ((end - begin) == 1)
        {
            std::cout << times[begin] << std::endl;
            break;
        }
    }
}

int main()
{
    int N, M, K;
    std::cin >> N;
    std::cin >> M;
    std::cin >> K;

    Bikers bikers;
    for (int i = 0; i < N; ++i)
    {
        Biker biker;
        biker.i = i;
        std::cin >> biker.n;
        std::cin >> biker.m;
        bikers.insert(std::move(biker));
    }

    Bikes bikes;
    for (int i = 0; i < M; ++i)
    {
        Bike bike;
        bike.i = i;
        std::cin >> bike.n;
        std::cin >> bike.m;
        bikes.insert(bike);
    }

    Distances distances;
    std::set<long long> times;
    for (auto& biker : bikers)
    {
        for (auto& bike : bikes)
        {
            Distance distance;
            distance.biker = biker;
            distance.bike = bike;
            distance.d = static_cast<long long>(std::pow((biker.n - bike.n), 2) + std::pow((biker.m - bike.m), 2));
            distances.push_back(std::move(distance));
            times.insert(distance.d);
        }
    }

    auto predicate = [](auto& first, auto& second) -> bool
    {
        return first.d < second.d;
    };
    std::sort(distances.begin(), distances.end(), predicate);


    for (auto& distance : distances)
    {
        //std::cout << distance.d << " " << "[" << distance.biker.n << "," << distance.biker.m << "] " << "["
        //          << distance.bike.n << "," << distance.bike.m << "]" << std::endl;
    }

    std::vector<long long> times2{times.begin(), times.end()};
    for (auto& time : times2)
    {
        //std::cout << time << std::endl;
    }

    Solve(distances, times2, K);
    return 0;
}
