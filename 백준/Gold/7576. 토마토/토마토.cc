#include<iostream>
#include<queue>
int map[1001][1001];
int dy[4] = { -1, 1, 0, 0};
int dx[4] = { 0, 0, 1, -1};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int M, N;
    std::cin >> M >> N;
    std::queue<std::pair<int, int>> qu;
    bool allRipe = true;
    
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            std::cin >> map[y][x];
            if (map[y][x] == 1)
            {
                qu.push({y, x});
            }
            if (map[y][x] == 0)
            {
                allRipe = false;
            }
        }
    }
    
    if (allRipe)
    {
        std::cout << 0 << "\n";
        return 0;
    }
    
    int maxDis = 0;
    while(!qu.empty())
    {
        auto pos = qu.front();
        qu.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            int nextY = dy[i] + pos.first;
            int nextX = dx[i] + pos.second;
            if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= M || map[nextY][nextX] != 0)
            {
                continue;
            }
            
            map[nextY][nextX] = map[pos.first][pos.second] + 1;
            maxDis = std::max(maxDis, map[nextY][nextX]);
            qu.push({nextY, nextX});
        }
    }
    
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            if (map[y][x] == 0)
            {
                std::cout << -1 << "\n";
                return 0;
            }
        }
    }
    
    std::cout << (maxDis - 1) << "\n";
    return 0;
}
