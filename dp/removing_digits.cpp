#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main(){

    int n;
    std::cin >> n;

    std::vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; ++i){
        if (dp[i] != INT_MAX){
            int num = n - i;
            while (num > 0){
                int last = num % 10;
                if (i + last <= n){
                    dp[i+last] = std::min(dp[i+last], dp[i] + 1);
                }
                num /= 10;
            }
        }
    }

    std::cout << dp[n] << std::endl;


    return 0;
}