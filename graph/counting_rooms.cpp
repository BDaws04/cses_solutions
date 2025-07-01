#include <vector>
#include <iostream>
#include <string>
#include <stack>

inline void bfs(const int i, const int j, std::vector<std::string>& grid){
    std::stack<std::pair<int, int>> q;
    std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    q.push({i, j});

    while (!q.empty()){
        std::pair<int, int> current = q.top();
        q.pop();
        int x = current.first, y = current.second;
        grid[x][y] = '#';

        for (auto dir : directions){
            int new_x = x + dir.first, new_y = y + dir.second;
            if (new_x >= 0 && new_y >= 0 && new_x < grid.size() && new_y < grid[0].size() && grid[new_x][new_y] == '.'){
                q.push({new_x, new_y});
            }
        }
    }
    
}

int main(){
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> grid(n);
    for (int i = 0; i < n;  ++i){
        std::cin >> grid[i];
    }

    int c = 0;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (grid[i][j] == '.'){
                c++;
                bfs(i, j, grid);
            }
        }
    }

    std::cout << c << std::endl;
    return 0;
}