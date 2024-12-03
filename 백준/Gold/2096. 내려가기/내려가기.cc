#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    // DP 배열
    std::vector<int> maxDP(3, 0), minDP(3, 0);
    std::vector<int> newMaxDP(3, 0), newMinDP(3, 0);

    // 첫 번째 줄 입력
    int a, b, c;
    std::cin >> a >> b >> c;
    maxDP[0] = minDP[0] = a;
    maxDP[1] = minDP[1] = b;
    maxDP[2] = minDP[2] = c;

    // 나머지 줄 처리
    for (int i = 1; i < N; ++i) {
        std::cin >> a >> b >> c;

        // 최대값 갱신
        newMaxDP[0] = std::max(maxDP[0], maxDP[1]) + a;
        newMaxDP[1] = std::max({maxDP[0], maxDP[1], maxDP[2]}) + b;
        newMaxDP[2] = std::max(maxDP[1], maxDP[2]) + c;

        // 최소값 갱신
        newMinDP[0] = std::min(minDP[0], minDP[1]) + a;
        newMinDP[1] = std::min({minDP[0], minDP[1], minDP[2]}) + b;
        newMinDP[2] = std::min(minDP[1], minDP[2]) + c;

        // 업데이트
        maxDP = newMaxDP;
        minDP = newMinDP;
    }

    // 결과 출력
    int maxScore = std::max({maxDP[0], maxDP[1], maxDP[2]});
    int minScore = std::min({minDP[0], minDP[1], minDP[2]});
    std::cout << maxScore << " " << minScore;

    return 0;
}
