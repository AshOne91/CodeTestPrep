#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::vector<bool> visited(100001, false);
    int N, K;
    std::cin>>N>>K;
    
    std::queue<std::pair<int, int>> qu;
    qu.push({N, 0});
    visited[N] = true;
    
    while(!qu.empty())
    {
        auto pos = qu.front();
        qu.pop();
        if (pos.first == K)
        {
            std::cout<<pos.second;
            return 0;
        }
        
        int nextPos = -1;
        int nextDistance = pos.second + 1;
        nextPos = pos.first - 1;
        if (0 <= nextPos && nextPos <= 100000 && visited[nextPos] == false)
        {
            visited[nextPos] = true;
            qu.push({nextPos, nextDistance});
        }
        nextPos = pos.first + 1;
        if (0 <= nextPos && nextPos <= 100000 && visited[nextPos] == false)
        {
            visited[nextPos] = true;
            qu.push({nextPos, nextDistance});
        }
        nextPos = pos.first * 2;
        if (0 <= nextPos && nextPos <= 100000 && visited[nextPos] == false)
        {
            visited[nextPos] = true;
            qu.push({nextPos, nextDistance});
        }
    }
}