// 최단 경로를 찾고, 음수 사이클이 있는지 확인
//벨만-포드 알고리즘은 단일 출발지점에서 모든 노드로 가는 최단 경로를 찾는 알고리즘입니다. 이 알고리즘의 특징은 다음과 같습니다:
// 음수 가중치를 처리할 수 있습니다.
// 음수 사이클을 탐지할 수 있습니다.

// 모든 간선에 대해, 그 간선을 지나가는 경로가 더 짧은 경로인지 확인하고, 
// 경로를 갱신합니다. 이 작업을 V-1번 반복합니다 (V는 노드의 수)
// 각 반복에서, 모든 간선을 검사하며, 경로가 갱신되면 그 경로로 더 좋은 결과를 얻을 수 있기 때문입니다.

// 음수 사이클 탐지
// 위의 과정이 끝난 후에도, 
// 여전히 경로가 갱신되는 경우가 있다면 이는 
// 음수 사이클이 존재한다는 의미입니다. 왜냐하면, 
// 음수 사이클을 계속해서 순회하면서 경로가 계속 갱신될 수 있기 때문입니다

// 다익스트라 알고리즘은 음수 가중치 간선을 처리할 수 없습니다. 
// 하지만 벨만-포드는 음수 가중치를 처리할 수 있고, 
// 음수 사이클이 존재하는지 확인하는 기능도 제공합니다. 
// 따라서 이 문제에서 음수 가중치를 가진 웜홀 간선이 존재하고, 
// 음수 사이클을 탐지하는 것이 중요한 문제이므로 벨만-포드 알고리즘이 적합합니다.

//| 알고리즘 | 경로 추적 가능? | 추가 배열 | 시간 복잡도 | 목적 |
//|:-----------:|:---------------:|:-----------:|:------------:|:----------:|
//| 플로이드-워셜 | 가능 | next[i][j] | O(V³) | 모든 노드 → 모든 노드 |
//| 벨만-포드 | 가능 | prev[v] | O(V × E) | 시작 노드 → 모든 노드 |


#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

bool bellman_ford(int n
, const std::vector<std::vector<std::pair<int, int>>>& graphs
, std::vector<int>& dist)
{
    for (int i = 1; i <= n - 1; ++i)
    {
        bool updated = false;
        for (int u = 1; u <= n; ++u)
        {
            for (auto& edge : graphs[u])
            {
                int v = edge.first;
                int cost = edge.second;
                if (dist[u] == INF)
                    continue;
                if (dist[u] + cost < dist[v])
                {
                    dist[v] = dist[u] + cost;
                    updated = true;
                }
            }
        }
        if (!updated)
            break;
    }

    for (int u = 1; u <= n; ++u)
    {
        for (auto& edge : graphs[u])
        {
            int v = edge.first;
            int cost = edge.second;
            if (dist[u] == INF)
                continue;
            if (dist[u] + cost < dist[v])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n, m, w;
        std::cin >> n >> m >> w;
        std::vector<std::vector<std::pair<int, int>>> graphs(n + 1);

        for (int j = 0; j < m; ++j)
        {
            int from, to, cost;
            std::cin >> from >> to >> cost;
            graphs[from].push_back({to, cost});
            graphs[to].push_back({from, cost});
        }

        for (int j = 0; j < w; ++j)
        {
            int from, to, cost;
            std::cin >> from >> to >> cost;
            graphs[from].push_back({to, -cost});
        }

        bool has_negative_cycle = false;
        for (int start = 1; start <= n; ++start)
        {
            std::vector<int> dist(n + 1, INF);
            dist[start] = 0;
            if (!bellman_ford(n, graphs, dist))
            {
                has_negative_cycle = true;
                break;
            }
        }

        if (has_negative_cycle)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}