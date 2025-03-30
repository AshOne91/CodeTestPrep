#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N, r, c;
    std::cin >> N >> r >> c;
    
    int result = 0;
    for (int i = N - 1; i >= 0; --i) {
        int half = 1 << i; // 2^i
        if (r & half) result += 2 * (1 << (2 * i));
        if (c & half) result += 1 * (1 << (2 * i));
    }
    
    std::cout << result;
    return 0;
}



