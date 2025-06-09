#include <iostream>
#include <limits>
#include <vector>

// 무한대를 의미하는 상수
const int INF = std::numeric_limits<int>::max();

int main()
{
    // 입출력 속도 향상
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int C, N; // C: 확보할 고객 수, N: 도시 수
    std::cin >> C >> N;

    // 도시별 홍보 비용과 그에 따른 고객 수 정보
    std::vector<std::pair<int, int>> cost_customer(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> cost_customer[i].first >> cost_customer[i].second;
    }

    // dp[i]: 고객 i명을 확보하기 위한 최소 비용
    // 최대 고객 수는 1100까지 충분히 잡아줌 (C 이상을 위해)
    int max_customer = C + 100;
    std::vector<int> dp(max_customer + 1, INF);
    dp[0] = 0; // 0명 확보하는 데 드는 비용은 0원

    // 각 도시의 홍보를 무한히 반복 가능 (Unbounded Knapsack)
    for (int i = 0; i < N; ++i)
    {
        int cost = cost_customer[i].first;
        int customer = cost_customer[i].second;

        // 고객 수 0~max까지 순회하며 DP 갱신
        for (int j = customer; j <= max_customer; ++j)
        {
            if (dp[j - customer] != INF)
            {
                dp[j] = std::min(dp[j], dp[j - customer] + cost);
            }
        }
    }

    // 고객 수 C 이상에서 가장 적은 비용 찾기
    int answer = INF;
    for (int i = C; i <= max_customer; ++i)
    {
        answer = std::min(answer, dp[i]);
    }

    // 결과 출력
    std::cout << answer << '\n';

    return 0;
}
