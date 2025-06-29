#include <iostream>
#include <vector>

int main() {
    const int MOD = 1e9 + 7;

    int n, x;
    std::cin >> n >> x;

    std::vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> coins[i];
    }

    std::vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int c : coins) {
        for (int i = c; i <= x; ++i) {
            dp[i] = (dp[i] + dp[i - c]) % MOD;
        }
    }

    std::cout << dp[x] << std::endl;
    return 0;
}
