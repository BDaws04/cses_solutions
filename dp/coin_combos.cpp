#include <iostream>
#include <vector>


int main(){

    const int MODULO = 1e9 + 7;

    int n, x;
    std::cin >> n >> x;

    std::vector<int> coins(n);
    for (int i = 0; i < n; ++i){
        std::cin >> coins[i];
    }

    std::vector<int> dp(x+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; ++i){
        for (int c : coins){
            if (i - c >= 0){
                dp[i] = (dp[i] + dp[i-c]) % MODULO;
            }
        }
    }

    std::cout << dp[x] << std::endl;

    return 0;
}