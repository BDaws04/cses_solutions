#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<bool> visited(n, false);
    std::vector<std::vector<int>> paths(n);

    for (int i = 0; i < m; ++i) {
        int start, end;
        std::cin >> start >> end;
        start --;
        end --;
        paths[start].push_back(end);
        paths[end].push_back(start);
    }

    std::vector<std::vector<int>> clusters;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            std::vector<int> group;
            std::queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int current = q.front();
                q.pop();
                group.push_back(current);

                for (auto e : paths[current]) {
                    if (!visited[e]) {
                        visited[e] = true;
                        q.push(e);
                    }
                }
            }

            clusters.push_back(group);
        }
    }

    std::cout << clusters.size() - 1 << std::endl;
    for (int i = 0; i < clusters.size() - 1; ++i){
        std::cout << (clusters[i][0] + 1) << " " << (clusters[i+1][0] + 1) << std::endl;
    }

    return 0;
}
