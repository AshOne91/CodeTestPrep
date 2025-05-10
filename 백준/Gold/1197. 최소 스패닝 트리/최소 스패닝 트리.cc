// ### 프림 알고리즘
// 프림 알고리즘은 **시작점에서부터 하나씩 간선을 추가**하여 최소신장트리를 구하는 방식입니다. 그리디 알고리즘의 일종으로, **현재까지 연결된 노드와 인접한 노드들 중 가장 적은 비용의 간선을 선택**하는 방식입니다.

// ### 기본 아이디어
// 1. **시작 노드를 정한다**.
// 2. **현재 트리에 연결된 노드들**에서 **가장 적은 비용**을 가진 간선을 선택하여 트리에 추가한다.
// 3. 모든 노드가 연결될 때까지 이 과정을 반복한다.

// ### 프림 알고리즘의 단계
// 1. **시작 노드를 선택**하고, 그 노드를 트리에 포함시킵니다.
// 2. 현재 트리에 연결된 노드들 중에서 가장 비용이 적은 간선을 선택하고, 그 간선에 연결된 노드를 트리에 포함시킵니다.
// 3. 이 과정을 모든 노드가 트리에 포함될 때까지 반복합니다.

#include <iostream>
#include <queue>
#include <unordered_map>
#include <limits>

const int INF = std::numeric_limits<int>::max();

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int V,E;
    std::cin>>V>>E;
    std::vector<std::vector<std::pair<int, int/*cost*/>>> graphs(V + 1);
    
    for (int i = 0; i < E; ++i)
    {
        int from, to, cost;
        std::cin>>from>>to>>cost;
        graphs[from].push_back({to, cost});
        graphs[to].push_back({from, cost});
    }
    std::unordered_map<int, bool> visited;
    
    auto cmp = [](std::pair<int, int>& left, std::pair<int, int>& right)
    {
        return left.second > right.second;
    };
    
    std::priority_queue<std::pair<int/*node*/, int/*cost*/>
        , std::vector<std::pair<int, int>>
        , decltype(cmp)> pq(cmp);
    
    pq.push({1, 0});
    int result = 0;
    while(!pq.empty())
    {
        int node = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        
        // 다익스트라 알고리즘 같이
        if (visited[node] == true)
        {
            continue;
        }
        visited[node] = true;
        result += cost;
        
        for(auto& next_node : graphs[node])
        {
            if (visited[next_node.first] == true)
            {
                continue;
            }
            
            pq.push({next_node.first, next_node.second});
        }
    }
    
    std::cout<<result;
}
