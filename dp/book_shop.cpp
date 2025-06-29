#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n, x;
    std::cin >> n >> x;

    std::vector<int> prices(n);
    std::vector<int> pages(n);

    for (int i = 0; i < n; ++i){
        std::cin >> prices[i];
    }
    for (int i = 0; i < n; ++i){
        std::cin >> pages[i];
    }

    std::vector<int> dp(x+1, 0);
    for (int i = 0; i < n; ++i){
        for (int j = x; j >= prices[i]; j--){
            dp[j] = std::max(dp[j], dp[j - prices[i]] + pages[i]);
        }
    }

    std::cout << *max_element(dp.begin(), dp.end()) << std::endl;
    return 0;
}