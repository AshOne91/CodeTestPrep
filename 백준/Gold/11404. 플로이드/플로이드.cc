#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();
#include <iostream>
#include <vector>
#include <limits>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    if (!(std::cin >> n >> m)) return 0;

    std::vector<std::vector<long long>> dist(n + 1,
        std::vector<long long>(n + 1, INF));

    // 대각선 0으로 초기화 (오류 수정: n 기준으로 초기화해야 함)
    for (int i = 1; i <= n; ++i)
    {
        dist[i][i] = 0;
    }

    // 간선 입력
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        long long w;
        std::cin >> u >> v >> w;
        if (u < 1 || u > n || v < 1 || v > n) continue; // 안전 검사
        if (w < dist[u][v]) dist[u][v] = w;
    }

    // 플로이드-워셜
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (dist[i][k] == INF) continue;
            for (int j = 1; j <= n; ++j)
            {
                if (dist[k][j] == INF) continue;
                long long through = dist[i][k] + dist[k][j];
                if (through < dist[i][j]) dist[i][j] = through;
            }
        }
    }

    // 결과 출력: 도달 불가시 0 출력(원래 코드 의도 유지)
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (dist[i][j] == INF)
                std::cout << "0 ";
            else
                std::cout << dist[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
