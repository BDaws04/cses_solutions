#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>

int main () {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> grid(n);
    for (int i = 0; i < n; ++i){
        std::cin >> grid[i];
    } 

    std::vector<std::vector<int>> ml(n, std::vector<int>(m, INT_MAX));
    std::queue<std::pair<int, int>> q;
    std::vector<std::pair<int, int>> dirs = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
    std::vector<char> dir_char = {'U', 'D', 'L', 'R'};

    std::pair<int, int> start = {-1, -1};

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (grid[i][j] == 'M'){
                q.push({i, j});
                ml[i][j] = 0;
            } else if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }


    while (!q.empty()){
        auto [i, j] = q.front(); q.pop();
        for (auto dir : dirs){
            int ni = i + dir.first;
            int nj = j + dir.second;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && 
                (grid[ni][nj] == '.' || grid[ni][nj] == 'A') && ml[ni][nj] == INT_MAX) {
                ml[ni][nj] = ml[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }

    std::vector<std::vector<char>> came_from(n, std::vector<char>(m, 'N'));
    std::vector<std::vector<int>> steps(n, std::vector<int>(m, -1));
    q.push(start);
    steps[start.first][start.second] = 0;
    came_from[start.first][start.second] = 'X';

    std::pair<int, int> exit = {-1, -1};
    bool found = false;
    while (!q.empty() && !found){
        auto [i, j] = q.front(); q.pop();

        if (i == 0 || j == 0 || i == n-1 || j == m-1){
            exit = {i, j};
            found = true;
            break;
        }

        for (int k = 0; k < 4; ++k){
            int ni = i + dirs[k].first;
            int nj = j + dirs[k].second;

            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                grid[ni][nj] == '.' &&
                came_from[ni][nj] == 'N' &&
                steps[i][j] + 1 < ml[ni][nj]) {
                
                came_from[ni][nj] = dir_char[k];
                steps[ni][nj] = steps[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }

    if (found) {
        std::cout << "YES\n";
        std::cout << steps[exit.first][exit.second] << "\n";

        std::string path;
        int x = exit.first, y = exit.second;
        while (came_from[x][y] != 'X') {
            char dir = came_from[x][y];
            path.push_back(dir);
            if (dir == 'U') x++;
            else if (dir == 'D') x--;
            else if (dir == 'L') y++;
            else if (dir == 'R') y--;
        }

        std::reverse(path.begin(), path.end());
        std::cout << path << "\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}
