#include <iostream>

int dp[41][2] = {{1, 0}, {0, 1}}; 

int main() {
    std::ios::sync_with_stdio(0); 
    std::cin.tie(0);

    for (int i = 2; i <= 40; ++i) 
        dp[i][0] = dp[i-1][0] + dp[i-2][0], dp[i][1] = dp[i-1][1] + dp[i-2][1];

    int T, N;
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        std::cout << dp[N][0] << ' ' << dp[N][1] << '\n';
    }
}
