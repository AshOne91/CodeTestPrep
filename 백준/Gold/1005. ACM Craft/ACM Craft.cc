#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T;
    std::cin >> T;

    while (T--)
    {
        int N, K;
        std::cin >> N >> K;

        std::vector<int> build_time(N + 1); // 각 건물 짓는 시간
        for (int i = 1; i <= N; ++i)
        {
            std::cin >> build_time[i];
        }

        std::vector<std::vector<int>> adj(N + 1); // 인접 리스트 (건설 순서)
        std::vector<int> indegree(N + 1, 0);      // 진입 차수

        for (int i = 0; i < K; ++i)
        {
            int X, Y;
            std::cin >> X >> Y;
            adj[X].push_back(Y);
            indegree[Y]++;
        }

        int W;
        std::cin >> W;

        std::vector<int> dp(N + 1, 0); // dp[i]: i번 건물 완성까지 최소 시간

        std::queue<int> q;

        // 먼저 지을 수 있는 건물 찾기 (선행 조건 없는 것들)
        for (int i = 1; i <= N; ++i)
        {
            if (indegree[i] == 0)
            {
                dp[i] = build_time[i]; // 시작 시간은 자기 건설 시간
                q.push(i);
            }
        }

        // 위상 정렬 + DP
        while (!q.empty())
        {
            int now = q.front();
            q.pop();

            for (int next : adj[now])
            {
                dp[next] = std::max(dp[next], dp[now] + build_time[next]);
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        std::cout << dp[W] << '\n';
    }

    return 0;
}
