#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();

int djk(int from, int to
, const std::vector<std::vector<std::pair<int, int>>>& graphs)
{
    std::vector<int> distance(graphs.size(), INF);
    
    auto cmp = [](const std::pair<int, int>& left
                 , const std::pair<int, int>& right)
    {
        return left.second > right.second;
    };
    std::priority_queue<std::pair<int, int>
        , std::vector<std::pair<int,int>>
        , decltype(cmp)> pq(cmp);
    pq.push({from, 0});
    distance[from] = 0;
    
    while(!pq.empty())
    {
        auto current = pq.top();
        pq.pop();
             
        if (current.second > distance[current.first])
        {
            continue;
        }
        
        if (current.first == to)
        {
            return distance[to];
        }
        
        for (auto next : graphs[current.first])
        {
            int next_node = next.first;
            int next_cost = next.second;
            
            if (distance[current.first] + next_cost > distance[next_node])
            {
                continue;
            }
            
            distance[next_node] = distance[current.first] + next_cost;
            pq.push({next_node, distance[next_node]});
        }
    }
    return distance[to];
}
// 다익스트라는 항상 "현재까지 최단거리로 갈 수 있는 노드"만을 확정해서 방문함.
// 다익스트라는 한 번 방문한 노드는 최단거리 확정임.
// distance를 검사하는 이유는, "이미 더 짧은 경로로 방문했던 노드를 또 큐에 넣었을 때 걸러내기 위해서"임.
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N, M, X;
    std::cin>>N>>M>>X;
    std::vector<std::vector<std::pair<int, int>>> graphs(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int from, to, cost;
        std::cin>>from>>to>>cost;
        graphs[from].push_back({to, cost});
    }
    
    std::vector<int> total_distance(N + 1, 0);
    for (int i = 1; i <= N; ++i)
    {
        total_distance[i] += djk(i, X, graphs);
    }
    
    for (int i = 1; i <= N; ++i)
    {
        total_distance[i] += djk(X, i, graphs);
    }
    
    int max_distance = -1;
    for (auto dis : total_distance)
    {
        if (dis > max_distance)
        {
            max_distance = dis;
        }
    }
    
    std::cout<<max_distance;
}
