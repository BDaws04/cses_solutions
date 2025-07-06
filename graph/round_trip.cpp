#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int s, e;
        std::cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    std::stack<std::pair<int, int>> stack;
    std::vector<bool> visited(n + 1, false);
    std::vector<int> parent(n + 1, -1);

    bool cycle_found = false;

    for (int i = 1; i <= n && !cycle_found; ++i) {
        if (!visited[i]) {
            stack.push({i, -1});

            while (!stack.empty() && !cycle_found) {
                auto [current, par] = stack.top();
                stack.pop();

                if (visited[current]) continue;
                visited[current] = true;
                parent[current] = par;

                for (auto nb : adj[current]) {
                    if (!visited[nb]) {
                        stack.push({nb, current});
                    } else if (nb != par) {
                        cycle_found = true;
                        std::vector<int> cycle_path;
                        cycle_path.push_back(nb);

                        int temp = current;
                        while (temp != nb && temp != -1) {
                            cycle_path.push_back(temp);
                            temp = parent[temp];
                        }
                        cycle_path.push_back(nb); 

                        std::reverse(cycle_path.begin(), cycle_path.end());

                        std::cout << cycle_path.size() << std::endl;

                        for (int node : cycle_path) {
                            std::cout << node << " ";
                        }
                        std::cout << std::endl;
                        break;
                    }
                }
            }
        }
    }

    if (!cycle_found) {
        std::cout << "IMPOSSIBLE" << std::endl;
    }

    return 0;
}


