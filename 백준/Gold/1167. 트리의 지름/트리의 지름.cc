#include <iostream>
#include <vector>
#include <limits>
#include <queue>

const int INF = std::numeric_limits<int>::max();

std::pair<int, int> bfs(int V
, int start
, const std::vector<std::vector<std::pair<int, int>>>& graphs)
{
    std::vector<int> distance(V+1, 0);
    std::vector<bool> visited(V+1, false);
    std::queue<int> qu;
    qu.push(start);
    distance[start] = 0;
    visited[start] = true;
    while(!qu.empty())
    {
        auto current_node = qu.front();
        qu.pop();
        
        for (auto& next_node : graphs[current_node])
        {
            if (visited[next_node.first] == true)
            {
                continue;
            }
            visited[next_node.first] = true;
            distance[next_node.first] = 
                distance[current_node] + next_node.second;
            qu.push(next_node.first);
        }
    }
    
    int max_distance = 0;
    int max_node = 0;
    for (int i = 1; i <= V; ++i)
    {
        if (distance[i] > max_distance)
        {
            max_distance = distance[i];
            max_node = i;
        }
    }
    
    return {max_node, max_distance};
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int V;
    std::cin>>V;
    std::vector<std::vector<std::pair<int, int>>> graphs(V+1);
    
    for (int i = 1; i <= V; ++i)
    {
        int node;
        std::cin>>node;
        
        while(true)
        {
            int input_1;
            std::cin>>input_1;
            if (input_1 == -1)
            {
                break;
            }
            int input_2;
            std::cin>>input_2;
            graphs[node].push_back({input_1, input_2});
        }
    }
    
    auto max_node = bfs(V, 1, graphs);
    auto result = bfs(V, max_node.first, graphs);
    
    std::cout<<result.second;
}