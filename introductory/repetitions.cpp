#include <vector>
#include <iostream>

int main () {
    std::string s;
    std::cin >> s;

    int n = s.size();
    int l = 0, max = 0;

    while (l < n){
        char c = s[l];
        int r = l + 1;
        while (r < n && s[r] == c){
            r ++;
        }
        max = std::max(max, r-l);
        l = r;
    }

    std::cout << max << std::endl;
    return 0;

}