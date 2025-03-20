#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);
    
    int N, M;
    std::cin>>N>>M;
    
    std::vector<int> sum(N + 1, 0);
    for (int i = 1; i <= N; ++i)
    {
        std::cin>>sum[i];
    }
    
    for (int i = 1; i <= N - 1; ++i)
    {
        sum[i + 1] = sum[i] + sum[i + 1];
    }
    
    for (int i = 0; i < M; ++i)
    {
        int start, end;
        std::cin>>start>>end;
        std::cout<<sum[end] - sum[start - 1]<<'\n';
    }
}