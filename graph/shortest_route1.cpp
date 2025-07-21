#include <vector>
#include <iostream>
#include <queue>

int main () {
    int n, m;
    std::cin >> n >> m;

    //{cost, dest}
    std::vector<std::vector<std::pair<long long, int>>> routes(n+1);
    for (int i = 0; i < m; ++i){
        int a, b;
        long long cost;
        std::cin >> a >> b >> cost;
        routes[a].push_back({cost, b});
    }

    std::vector<long long> distances(n, 0);

    //{cost, dest}
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
    for (const auto &p : routes[1]){
        pq.push({p.first, p.second});
    }

    while (!pq.empty()){
        auto current = pq.top();
        pq.pop();
        long long cost = current.first;
        int dest = current.second;

        if (distances[dest-1] == 0 && dest != 1){
            distances[dest-1] = cost;
            for (auto n : routes[dest]){
                pq.push({cost + n.first, n.second});
            }
        }

    }

    for (auto d : distances){
        std::cout << d << " ";
    }

    return 0;
}