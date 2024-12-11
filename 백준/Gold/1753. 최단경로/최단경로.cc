#include <iostream>
#include <queue>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();
int V, E;

void dijkstra(int start, const std::vector<std::vector<std::pair<int, int>>>& graphs)
{
    std::vector<int> dist(V + 1, INF);
    auto cmp = [](std::pair<int, int>& left, std::pair<int, int>& right)
    {
        return left.second > right.second;  
    };
    
    std::priority_queue<std::pair<int, int>
        , std::vector<std::pair<int, int>>
        , decltype(cmp)> pq(cmp);
    
    pq.push({start, 0});
    dist[start] = 0;
    
    while (!pq.empty())
    {
        auto current = pq.top();
        pq.pop();
        
        int currentNode = current.first;
        int currentDist = current.second;
        
        if (currentDist > dist[currentNode])
        {
            continue;
        }
        
        for (const auto& [nextNode, nextWeight] : graphs[currentNode])
        {
            if (dist[nextNode] > nextWeight + currentDist)
            {
                dist[nextNode] = nextWeight + currentDist;
                pq.push({nextNode, dist[nextNode]});
            }
        }
    }
    
    // 모든 노드까지의 최단 거리 출력
    for (int i = 1; i <= V; ++i)
    {
        if (dist[i] == INF)
            std::cout << "INF\n";
        else
            std::cout << dist[i] << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    
    std::cin >> V >> E;
    int K;
    std::cin >> K;
    
    // graphs는 각 노드의 인접 리스트를 저장
    std::vector<std::vector<std::pair<int, int>>> graphs(V + 1);
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        graphs[u].push_back({v, w});
    }
    
    dijkstra(K, graphs);
}
