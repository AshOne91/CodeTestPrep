#include<iostream>
#include<vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::cin>>N;
    
    std::vector<std::vector<int>> triangle(N,std::vector<int>(N));
    
    for(int y = 1; y <= N; ++y)
    {
        for(int x = 0; x < y; ++x)
        {
            std::cin>>triangle[y-1][x];
        }
    }
    
    for (int y = (N - 1); 0 < y; --y)
    {
        for (int x = 0; x < y; ++x)
        {
            triangle[y-1][x] = std::max(triangle[y-1][x] + triangle[y][x],triangle[y-1][x] + triangle[y][x + 1]); 
        }
    }
    
    std::cout<<triangle[0][0];
}