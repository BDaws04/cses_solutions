#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

int main () {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> connections(n+1);
    for (int i = 0; i < m; ++i){
        int b, e;
        std::cin >> b >> e;
        connections[b].push_back(e);
        connections[e].push_back(b);
    }

    std::queue<int> q;
    std::vector<bool> visited(n+1, false);
    std::vector<int> parents(n+1, -1);
    q.push(1);
    visited[1] = true;
    bool found = false;

    while (!q.empty()){
        int current = q.front();
        q.pop();

        if (current == n){
            found = true;
            break;
        }

        for (auto n : connections[current]){
            if (visited[n] == false){
                visited[n] = true;
                q.push(n);
                parents[n] = current;
            }
        }


    }

    if (!found){
        std::cout << "IMPOSSIBLE" << std::endl;
    }
    else {

        std::vector<int> path;
        int current = n;
        path.push_back(current);

        while (current != 1) {
            current = parents[current];
            path.push_back(current);
        }

        std::reverse(path.begin(), path.end());

        std::cout << path.size() << std::endl;

        for (int node : path) {
            std::cout << node << " ";
        
        }
    }

    return 0;

}