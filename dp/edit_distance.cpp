#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int main () {
    std::string f, s;
    std::cin >> f;
    std::cin >> s;
    int n = f.size();
    int m = s.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, INT_MAX));
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i;
    }

    for (int i = 0; i <= m; ++i) {
        dp[0][i] = i;   
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (f[i-1] == s[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + std::min({
                    dp[i-1][j],
                    dp[i][j-1],
                    dp[i-1][j-1],
                });
            }
        }
    }

    std::cout << dp[n][m] << std::endl;

    return 0;

}