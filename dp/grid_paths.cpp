#include <iostream>
#include <vector>
#include <string>

int main(){

    int n;
    std::cin >> n;

    const int MODULO = 1e9 + 7;

    std::vector<std::string> grid(n);
    for (int i = 0; i < n; ++i){
        std::cin >> grid[i];
    }
    
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i){
        if (grid[0][i] == '*'){
            break;
        }
        dp[0][i] = 1;
    }

    for (int i = 0; i < n; ++i){
        if (grid[i][0] == '*'){
            break;
        }
        dp[i][0] = 1;
    }

    for (int i = 1; i < n; ++i){
        for (int j = 1; j < n; ++j){
            if (grid[i][j] == '*'){
                continue;
            }
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MODULO;
        }
    }

    std::cout << dp[n-1][n-1] << std::endl;
    return 0;
}