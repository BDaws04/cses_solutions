#include <iostream>
#include <vector>
#include <queue>
#include <utility>

struct Edge {
    int u, v;
    long long w;
};

const long long INF = 1e18;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        std::cin >> u >> v >> w;
        edges[i] = {u, v, -w};
    }

    std::vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    for (int i = 1; i <= n; ++i) {
        for (auto &e : edges) {
            if (dist[e.u] < INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;           
            }
        }
    }

    std::vector<bool> affected(n+1, false);
    for (int i = 1; i <= n; i++) {
        for (auto &e : edges) {
            if (dist[e.u] < INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = -INF;
                affected[e.v] = true;
            }
            if (affected[e.u]) affected[e.v] = true;
        }
    }

    if (affected[n]) {
        std::cout << "-1" << std::endl;
    }
    else {
        std::cout << -dist[n] << std::endl;
    }

    return 0;
}