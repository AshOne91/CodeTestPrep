#include<iostream>
#include<vector>
#include<limits>

int main()
{
    
    int N,M,B;
    std::cin>>N>>M>>B;
    std::vector<std::vector<int>> map(N, std::vector<int>(M, -1));
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            std::cin>>map[y][x];
        }
    }
    
    int minTime = std::numeric_limits<int>::max();
    int minHigh = std::numeric_limits<int>::max();
    int time = 0;
    for (int h = 0; h <= 256; ++h)
    {
        int remove = 0;
        int stack = 0;
        for (int y = 0; y < N; ++y)
        {
            for (int x = 0; x < M; ++x)
            {
                if (map[y][x] > h)
                {
                    remove += map[y][x] - h;
                }
                else if (map[y][x] == h)
                {
                    continue;
                }
                else if (map[y][x] < h)
                {
                    stack += h - map[y][x];
                }
            }
        }
        // 작업이 가능하다.
        if (remove + B >= stack)
        {
            time = remove * 2 + stack;
            if (time <= minTime)
            {
                minTime = time;
                minHigh = h;
            }
        }
    }
    std::cout<<minTime<<' '<<minHigh;
}