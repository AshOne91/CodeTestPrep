#include <stdio.h>

#define MAX_K 100000  // 최대 배낭 무게
#define MAX_N 100     // 최대 아이템 개수

int dp[MAX_K + 1];      // DP 배열 (배낭 무게별 최대 가치 저장)
int weight[MAX_N];      // 각 아이템의 무게
int value[MAX_N];       // 각 아이템의 가치

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &weight[i], &value[i]);
    }

    for (int j = 0; j < N; ++j) {
        int w = weight[j], v = value[j];

        // DP 배열을 역순으로 업데이트하여 중복 사용 방지
        for (int i = K; i >= w; --i) {
            int newValue = dp[i - w] + v;
            if (newValue > dp[i]) dp[i] = newValue;
        }
    }

    printf("%d\n", dp[K]);  // 결과 출력 최적화
    return 0;
}
