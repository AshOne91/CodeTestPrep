#include<iostream>
#include<queue>
#include<limits>
#include<vector>
#include<queue>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(int start, int end
, const vector<vector<pair<int, int>>>& graph
, vector<int>& dist)
{
    auto cmp = [](pair<int, int>& left, pair<int, int>& right){
        return left.second > right.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    
    dist[start] = 0;
    pq.push({start, 0});
    
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
        
        for (const auto& adjNode : graph[currentNode])
        {
            int nextNode = adjNode.first;
            int nextDist = adjNode.second;
            if (dist[currentNode] + nextDist < dist[nextNode])
            {
                dist[nextNode] = dist[currentNode] + nextDist;
                pq.push({nextNode, dist[nextNode]});
            }
        }
    }
}

int main()
{
    int N, E;
    std::cin>>N>>E;
    
    vector<vector<pair<int, int>>> graph(N + 1);
    
    for (int i = 0; i < E; ++i)
    {
        int a, b, c;
        std::cin>>a>>b>>c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
    int v1, v2;
    std::cin>>v1>>v2;
    
    //v1<->v2
    vector<int> dist1(N + 1, INF);
    dijkstra(v1, v2, graph, dist1);
    int distValue1 = dist1[v2];
    
    //1->v1
    vector<int> dist2(N + 1, INF);
    dijkstra(1, v1, graph, dist2);
    int distValue2 = dist2[v1];
    
    //v2->N
    vector<int> dist3(N + 1, INF);
    dijkstra(v2, N, graph, dist3);
    int distValue3 = dist3[N];
    
    //1->v2
    vector<int> dist4(N + 1, INF);
    dijkstra(1, v2, graph, dist4);
    int distValue4 = dist4[v2];
    
    //v1->N
    vector<int> dist5(N + 1, INF);
    dijkstra(v1, N, graph, dist5);
    int distValue5 = dist5[N];
    
    //1->v1->v2->N
    int ans1 = -1;
    if (distValue2 != INF && distValue1 != INF && distValue3 != INF)
    {
        ans1 = distValue2 + distValue1 + distValue3;
    }
    //1->v2->v1->N
    int ans2 = -1;
    if (distValue4 != INF && distValue1 != INF && distValue5 != INF)
    {
        ans2 = distValue4 + distValue1 + distValue5;
    }
    
    if (ans1 == -1 && ans2 == -1)
    {
        std::cout << -1;
        return 0;
    }
    
    std::cout<<std::min(ans1, ans2);
    return 0;
}