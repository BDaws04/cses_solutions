#include <vector>
#include <iostream>

int main(){

    const int MODULO = 1e9 + 7;

    int n;
    std::cin >> n;

    std::vector<int> dp(n+1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++){
        for (int d = 1; d <= 6; d++){
            if (i - d >= 0){
                dp[i] = (dp[i] + dp[i - d]) % MODULO;
            }
        }
    }

    std::cout << dp[n] << std::endl;
    return 0;

}