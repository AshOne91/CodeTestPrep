#include <iostream>
#include <vector>
#include <limits>

const long long INF = (long long)1e15; // 충분히 큰 값 (long long)

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    // dist: i->j 최소 비용, next: i->j 가는 경로에서 i 다음에 갈 도시
    std::vector<std::vector<long long>> dist(n + 1, std::vector<long long>(n + 1, INF));
    std::vector<std::vector<int>> next(n + 1, std::vector<int>(n + 1, 0));
    
    // 자기 자신으로 가는 비용은 0
    for (int i = 1; i <= n; ++i)
    {
        dist[i][i] = 0;
    }
    
    // 간선 입력 (같은 u->v 여러개일 수 있으므로 최솟값 유지)
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        long long w;
        std::cin >> u >> v >> w;
        if (w < dist[u][v])
        {
            dist[u][v] = w;
            next[u][v] = v;
        }
    }
    
    // Floyd–Warshall (경로 복원용 next도 같이 갱신)
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (dist[i][k] == INF) continue;
            for (int j = 1; j <= n; ++j)
            {
                if (dist[k][j] == INF) continue;
                long long cand = dist[i][k] + dist[k][j];
                if (cand < dist[i][j])
                {
                    dist[i][j] = cand;
                    next[i][j] = next[i][k];
                }
            }
        }
    }
    
    // 1) 거리 출력 (도달 불가하면 0)
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (dist[i][j] == INF) std::cout << 0;
            else std::cout << dist[i][j];
            if (j < n) std::cout << ' ';
        }
        std::cout << '\n';
    }
    
    // 2) 경로 출력 (도달 불가하거나 i==j이면 0)
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (dist[i][j] == INF || i == j)
            {
                std::cout << 0 << '\n';
                continue;
            }
            
            // 역추적: next를 따라가면 전체 경로(노드 리스트)가 나옴
            std::vector<int> path;
            int cur = i;
            path.push_back(cur);
            while (cur != j)
            {
                cur = next[cur][j];
                path.push_back(cur);
            }
            
            std::cout << path.size() << ' ';
            for (int idx = 0; idx < (int)path.size(); ++idx)
            {
                if (idx) std::cout << ' ';
                std::cout << path[idx];
            }
            std::cout << '\n';
        }
    }
    
    return 0;
}
