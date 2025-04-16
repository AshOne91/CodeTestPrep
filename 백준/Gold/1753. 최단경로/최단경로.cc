#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int V, E;
    std::cin>>V>>E;
    int K;
    std::cin>>K;
    
    auto cmp = [](const std::pair<int, int>& left
                 , const std::pair<int, int>& right)
    {
        return left.second > right.second;
    };
    std::priority_queue<std::pair<int, int>
        , std::vector<std::pair<int, int>>
        , decltype(cmp)> pq(cmp);
    std::vector<std::vector<std::pair<int,int>>> graph(V + 1);
    std::vector<int> distance(V + 1, INF);
    
    for (int i = 0; i < E; ++i)
    {
        int from, to, cost;
        std::cin>>from>>to>>cost;
        graph[from].push_back({to, cost});
    }
    
    pq.push({K, 0});
    distance[K] = 0;
    
    while(!pq.empty())
    {
        auto current = pq.top();
        auto current_node = current.first;
        auto current_cost = current.second;
        pq.pop();
        
        if (current_cost > distance[current_node])
        {
            continue;
        }
        
        for (auto& next : graph[current_node])
        {
            int next_node = next.first;
            int next_cost = next.second;
            if (distance[next_node] >  distance[current_node] + next_cost)
            {
                distance[next_node] = distance[current_node] + next_cost;
                pq.push({next_node, distance[next_node]});
            }
        }
    }
    
    for (int i = 1; i <= V; ++i)
    {
        if (distance[i] == INF)
        {
            std::cout<<"INF\n";
        }
        else
        {
            std::cout<<distance[i]<<'\n';
        }
    }
}