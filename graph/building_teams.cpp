#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> connections(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    std::vector<int> teams(n + 1, -1);

    for (int i = 1; i <= n; ++i) {
        if (teams[i] == -1) {
            std::queue<int> q;
            q.push(i);
            teams[i] = 1;

            while (!q.empty()) {
                int current = q.front();
                q.pop();

                for (int neighbor : connections[current]) {
                    if (teams[neighbor] == -1) {
                        teams[neighbor] = 3 - teams[current]; 
                        q.push(neighbor);
                    } else if (teams[neighbor] == teams[current]) {
                        std::cout << "IMPOSSIBLE" << std::endl;
                        return 0;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << teams[i] << (i == n ? "\n" : " ");
    }

    return 0;
}
