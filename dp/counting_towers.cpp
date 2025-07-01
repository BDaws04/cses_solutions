#include <iostream>
#include <vector>
#include <algorithm>

void solve(const int n){
}

#define ll long long
const int MOD = 1000000007;

int main(){
    int n;
    std::cin >> n;

    std::vector<int> inp(n);

    for (int i = 0; i < n; ++i){
        std::cin >> inp[i];
    }

    int max_comp = *std::max_element(inp.begin(), inp.end());

    std::vector<ll> towers(max_comp+1), psum(max_comp+1);
    towers[1] = 2;
    psum[1] = 1;
    for (int i = 2; i <= max_comp; i++) {
        psum[i] = (psum[i-1] + towers[i-1]) % MOD;
        towers[i] = psum[i] + 3*(towers[i-1] - psum[i-1]) + towers[i-1];
        towers[i] = (towers[i] % MOD + MOD) % MOD;
    }

 
    for (int i : inp){
        std::cout << towers[i] << std::endl;
    }

    return 0;
}