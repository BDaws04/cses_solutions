#include <iostream>
#include <vector>
#include <algorithm>

int main () {
    int n;
    std::cin >> n;

    std::vector<int> nums(n-1);

    for (int i = 0; i < n-1; ++i){
        std::cin >> nums[i];
    }

    std::sort(nums.begin(), nums.end());
    bool found = false;

    for (int i = 1; i <= n-1; ++i){
        if (nums[i-1] != i){
            std::cout << i << std::endl;
            found = true;
            break;
        }
    }

    if (!found){
        std::cout << n << std::endl;
    }

    return 0;
}