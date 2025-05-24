#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<int> A(N + 1);  // 수열 (1번부터 시작)
    for (int i = 1; i <= N; ++i)
        std::cin >> A[i];

    // dp[s][e] = A[s]부터 A[e]까지가 팰린드롬이면 1, 아니면 0
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(N + 1, 0));

    // 1. 길이 1짜리 구간은 무조건 팰린드롬
    for (int i = 1; i <= N; ++i)
        dp[i][i] = 1;

    // 2. 길이 2짜리 구간 검사
    for (int i = 1; i < N; ++i) {
        if (A[i] == A[i + 1])
            dp[i][i + 1] = 1;
    }

    // 3. 길이 3 이상 구간 검사
    for (int len = 3; len <= N; ++len) { // 구간 길이
        for (int s = 1; s <= N - len + 1; ++s) { // 시작점
            int e = s + len - 1; // 끝점
            if (A[s] == A[e] && dp[s + 1][e - 1] == 1)
                dp[s][e] = 1;
        }
    }

    int M;
    std::cin >> M;
    while (M--) {
        int s, e;
        std::cin >> s >> e;
        std::cout << dp[s][e] << "\n";
    }

    return 0;
}
