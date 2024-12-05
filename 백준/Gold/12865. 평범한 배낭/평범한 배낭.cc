#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> items(N);
    for (int i = 0; i < N; ++i) {
        cin >> items[i].first >> items[i].second; // 무게, 가치
    }

    // DP 배열 생성
    vector<int> dp(K + 1, 0);

    // 물건들을 하나씩 처리
    for (int i = 0; i < N; ++i) {
        int weight = items[i].first;
        int value = items[i].second;

        // 뒤에서부터 순회하여 dp 갱신
        for (int j = K; j >= weight; --j) {
            dp[j] = max(dp[j], dp[j - weight] + value);
        }
    }

    // 최대 가치 출력
    cout << dp[K] << endl;

    return 0;
}