#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int n;
    std::cin>>n;
    std::vector<std::vector<std::pair<int, int>>> graphs(n + 1);
    std::vector<int> distance(n + 1, 0);
    std::vector<bool> visited(n + 1, false);
    
    int from, to, cost;
    while(std::cin>>from>>to>>cost)
    {
        graphs[from].push_back({to, cost});
        graphs[to].push_back({from, cost});
    }
    
    std::queue<int> qu;
    qu.push(1);
    visited[1] = true;
    distance[1] = 0;
    int max_node = 1;
    int max_distance = -1;
    while(!qu.empty())
    {
        int current_node = qu.front();
        qu.pop();
        if (distance[current_node] > max_distance)
        {
            max_distance = distance[current_node];
            max_node = current_node;
        }
        for(auto next_node : graphs[current_node])
        {
            if (visited[next_node.first] == true)
            {
                continue;
            }
            visited[next_node.first] = true;
            distance[next_node.first] = distance[current_node] + next_node.second;
            qu.push(next_node.first);
        }
    }
    
    std::fill(distance.begin(), distance.end(), 0);
    std::fill(visited.begin(), visited.end(), false);
    qu.push(max_node);
    visited[max_node] = true;
    distance[max_node] = 0;
    int result = -1;
    while(!qu.empty())
    {
        int current_node = qu.front();
        qu.pop();
        if (distance[current_node] > result)
        {
            result = distance[current_node];
        }
        for(auto next_node : graphs[current_node])
        {
            if (visited[next_node.first] == true)
            {
                continue;
            }
            visited[next_node.first] = true;
            distance[next_node.first] = distance[current_node] + next_node.second;
            qu.push(next_node.first);
        }
    }
    
    std::cout<<result;
}