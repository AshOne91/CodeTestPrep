#include<iostream>
#include<queue>
#include<vector>
#include<limits>

const int INF = std::numeric_limits<int>::max();

std::vector<int> dist(100001, INF);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int N, K;
    std::cin>>N>>K;
    auto cmp = [](std::pair<int, int>& left, std::pair<int, int>& right)
    {
        return left.second > right.second;
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> qu(cmp);

    
    if (N == K)
    {
        std::cout<<0;
        return 0;
    }
    
    //2*X, 0
    qu.push({N*2, 0});
    //x-1, x+1, 1
    qu.push({N-1, 1});
    qu.push({N+1, 1});
    
    while(!qu.empty())
    {
        auto current = qu.top();
        qu.pop();
        int currentPos = current.first;
        int currentDist = current.second;
        if (currentPos < 0 || 100000 < currentPos)
        {
            continue;
        }
        
        if (currentDist >= dist[currentPos])
        {
            continue;
        }
        dist[currentPos] = currentDist;
        
        if (currentPos == K)
        {
            std::cout<<dist[currentPos];
            return 0;
        }
        
        qu.push({currentPos*2, dist[currentPos]});
        qu.push({currentPos-1, dist[currentPos] + 1});
        qu.push({currentPos+1, dist[currentPos] + 1});
    }
    return 0;
}