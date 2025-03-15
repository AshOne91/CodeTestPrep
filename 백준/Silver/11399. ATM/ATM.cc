#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, sum = 0, res = 0;
    std::cin >> N;
    std::vector<int> v(N);
    
    for (int &x : v) std::cin >> x;
    std::sort(v.begin(), v.end());
    
    for (int x : v) res += (sum += x);
    
    std::cout << res;
}
