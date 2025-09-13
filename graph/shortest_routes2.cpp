#include <iostream>
#include <vector>
#include <algorithm>

const long long INF = 1e15;

void floyd_warshall(std::vector<std::vector<long long>>& dist) {
    int v = dist.size();
    for (int k = 0; k < v; ++k) {
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<std::vector<long long>> dist(n, std::vector<long long>(n, INF));
    for (int i = 0; i < n; i++) dist[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int start, end; long long cost;
        std::cin >> start >> end >> cost;
        --start; --end;
        dist[start][end] = std::min(dist[start][end], cost);
        dist[end][start] = std::min(dist[end][start], cost); 
    }

    floyd_warshall(dist);

    while (q--) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;
        if (dist[u][v] >= INF/2) std::cout << -1 << "\n";
        else std::cout << dist[u][v] << "\n";
    }

    return 0;
}
