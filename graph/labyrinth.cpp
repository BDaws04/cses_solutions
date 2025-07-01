#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

int main(){
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> grid(n);
    for (int i = 0; i < n; ++i){
        std::cin >> grid[i];
    }

    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    std::vector<std::vector<std::pair<int,int>>> parent(n, std::vector<std::pair<int,int>>(m, {-1,-1}));
    std::vector<std::vector<char>> move_dir(n, std::vector<char>(m, 0));

    std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    std::vector<char> dir_chars = {'R', 'D', 'U', 'L'};

    bool found = false;
    int start_x = -1, start_y = -1;

    for (int i = 0; i < n && !found; ++i){
        for (int j = 0; j < m && !found; ++j){
            if (grid[i][j] == 'A'){
                q.emplace(i, j);
                visited[i][j] = true;
                start_x = i;
                start_y = j;
                found = true;
            }
        }
    }

    if (!found){
        std::cout << "invalid grid" << std::endl;
        return 1;
    }

    bool sol = false;
    int end_x = -1, end_y = -1;

    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        if (grid[x][y] == 'B'){
            sol = true;
            end_x = x;
            end_y = y;
            break;
        }

        for (int i = 0; i < (int)directions.size(); ++i){
            int new_x = x + directions[i].first;
            int new_y = y + directions[i].second;

            if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < m &&
                grid[new_x][new_y] != '#' && !visited[new_x][new_y]){
                visited[new_x][new_y] = true;
                parent[new_x][new_y] = {x, y};
                move_dir[new_x][new_y] = dir_chars[i];
                q.emplace(new_x, new_y);
            }
        }
    }

    if (!sol){
        std::cout << "NO" << std::endl;
    } else {
        std::string path;
        int cx = end_x, cy = end_y;

        while (!(cx == start_x && cy == start_y)) {
            path.push_back(move_dir[cx][cy]);
            auto p = parent[cx][cy];
            cx = p.first;
            cy = p.second;
        }

        std::reverse(path.begin(), path.end());

        std::cout << "YES" << std::endl;
        std::cout << path.size() << std::endl;
        std::cout << path << std::endl;
    }

    return 0;
}

