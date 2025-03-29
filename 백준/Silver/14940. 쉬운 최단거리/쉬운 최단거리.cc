// 0은 갈 수 없는 땅 1은 갈 수 있는 땅 2는 목표 지점
// 원래 갈 수 있는 땅인 부분 중에서 도달할 수 없는 위치는 -1
#include <iostream>
#include <vector>
#include <queue>

std::vector<std::pair<int,int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int n, m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> map(n, std::vector<int>(m, -1));
    int startY, startX;
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < m; ++x)
        {
            int num;
            std::cin>>num;
            if (num == 2)
            {
                startY = y;
                startX = x;
                map[startY][startX] = 0;
            }
            if (num == 0)
            {
                map[y][x] = 0;
            }
        }
    }
    
    std::queue<std::pair<int/*y*/, int/*x*/>> qu;
    qu.push({startY, startX});
    
    while(!qu.empty())
    {
        auto pos = qu.front();
        qu.pop();
        
        for (auto& dir : dirs)
        {
            int nextY = pos.first + dir.first;
            int nextX = pos.second + dir.second;
            if (nextX < 0 || m <= nextX)
                continue;
            if (nextY < 0 || n <= nextY)
                continue;
            
            if (map[nextY][nextX] != -1)
            {
                continue;
            }
            map[nextY][nextX] = map[pos.first][pos.second] + 1;
            qu.push({nextY, nextX});
        }
    }
    
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < m; ++x)
        {
            std::cout<<map[y][x]<<' ';
        }
        std::cout<<'\n';
    }
}