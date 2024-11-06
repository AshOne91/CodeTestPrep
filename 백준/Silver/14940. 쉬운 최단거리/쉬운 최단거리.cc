#include<iostream>
#include<vector>
#include<queue>

std::vector<std::pair<int, int>> dir = {{-1, 0},{0, 1},{1, 0},{0, -1}};

int main()
{
    std::ios::sync_with_stdio(false);  // 입출력 속도 최적화
    std::cin.tie(NULL);                // 입출력 묶음 해제
    std::cout.tie(NULL);                // 입출력 묶음 해제

    int n, m;
    std::cin>>n>>m;
    
    std::vector<std::vector<int>> map(n, std::vector<int>(m, 0));
    std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));
    int startY = -1;
    int startX = -1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin>>map[i][j];
            if (map[i][j] == 0)
            {
                dist[i][j] = 0;
            }
            else if (map[i][j] == 2)
            {
                startY = i;
                startX = j;
            }
        }
    }
    
    std::queue<std::pair<int, int>> qu;
    qu.push({startY, startX});
    dist[startY][startX] = 0;
    
    while(!qu.empty())
    {
        auto curPos = qu.front();
        qu.pop();
        
        for (auto& pos : dir)
        {
            int nextY = pos.first + curPos.first;
            int nextX = pos.second + curPos.second;
            
            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m || map[nextY][nextX] != 1)
            {
                continue;        
            }
            
            qu.push({nextY, nextX});
            map[nextY][nextX] = 2;
            dist[nextY][nextX] = dist[curPos.first][curPos.second] + 1;
        }
    }
    
    for (int i = 0; i < n ; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cout<<dist[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}