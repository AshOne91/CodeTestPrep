#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    
    int N, M;
    std::cin>>N>>M;
    std::vector<int> sum(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        std::cin>>sum[i];
        sum[i] = sum[i] + sum[i - 1];
    }

    for (int i = 0; i < M; ++i)
    {
        int start, end;
        std::cin>>start>>end;
        std::cout<<sum[end] - sum[start - 1]<<'\n';
    }
    return 0;
}