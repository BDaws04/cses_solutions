#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main (){

    int n, x;
    std::cin >> n >> x;

    std::vector<int> coins(n);

    for (int i = 0; i < n; ++i){
        std::cin >> coins[i];
    }

    std::vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= x; ++i){
        for (int c : coins){
            if (i >= c && dp[i - c] != INT_MAX) {
                dp[i] = std::min(dp[i], dp[i - c] + 1);
            }
        }
    }

    if (dp[x] == INT_MAX){
        std::cout << -1 << std::endl;
    }
    else {
        std::cout << dp[x] << std::endl;
    }

    return 0;


}