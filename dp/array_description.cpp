#include <iostream>
#include <vector>

int main () {

    const int MODULO = 1e9 +7;

    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i){
        std::cin >> nums[i];
    }

    std::vector<std::vector<long long>> dp(n, std::vector<long long>(m+1, 0));
    if (nums[0] == 0){
        for (int i = 1; i <= m; ++i){
            dp[0][i] = 1;
        }
    } 
    else {
        dp[0][nums[0]] = 1;
    }

    for (int i = 1; i < n; ++i){
        if (nums[i] == 0){
            for (int j = 1; j <= m; ++j){
                for (int diff = -1; diff <= 1; ++diff){
                    int prev_j = j + diff;
                    if (prev_j >= 1 && prev_j <= m){
                        dp[i][j] = (dp[i][j] + dp[i-1][prev_j]) % MODULO;
                    }
                }
            }
        }
        else {
            int j = nums[i];
            for (int diff = -1; diff <= 1; ++diff){
                int prev_j = j + diff;
                if (prev_j >= 1 && prev_j <= m){
                    dp[i][j] = (dp[i][j] + dp[i-1][prev_j]) % MODULO;
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= m; ++i){
        ans = (ans + dp[n-1][i]) % MODULO;
    }

    std::cout << ans << std::endl;

    return 0;

}