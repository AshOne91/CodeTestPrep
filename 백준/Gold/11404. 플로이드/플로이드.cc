#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(n+1, INF));
    for (int i = 1; i <= n; ++i)
    {
        dp[i][i] = 0;
    }
    
    int m;
    std::cin>>m;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        dp[a][b] = std::min(dp[a][b], c);
    }

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (dp[i][k] != INF && dp[k][j] != INF)
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (dp[i][j] == INF)
            {
               dp[i][j] = 0; 
            }
            std::cout<<dp[i][j]<<' ';
        }
        std::cout<<'\n';
    }
}