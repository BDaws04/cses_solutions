#include <vector>
#include <iostream>

int main () {
    int n;
    std::cin >> n;

    std::vector<long long> vals(n);
    for (int i = 0; i < n; ++i){
        std::cin >> vals[i];
    }

    long long c = 0;

    for (int i = 1; i < n; ++i){
        if (vals[i] < vals[i-1]){
            c += (vals[i-1] - vals[i]);
            vals[i] = vals[i-1]; 
        }
    }

    std::cout << c << std::endl;

    return 0;


}