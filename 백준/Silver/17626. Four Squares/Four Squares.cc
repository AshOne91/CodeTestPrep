#include<iostream>
#include<vector>
#include <climits>

std::vector<int> dp(50001, INT_MAX);

int main()
{
    int n;
    std::cin>>n;
    
    dp[0] = 0;  // 0을 만드는 데 필요한 제곱수 항의 개수는 0
    
    //기저 생성
    //제곱수는 항상 1;
    for (int i = 1; i * i <= n; ++i)
    {
        dp[i * i] = 1;
    }
    
    // 최소 항 계산
    for (int i = 1; i <= n; ++i) 
    {
        for (int j = 1; j * j <= i; ++j) 
        {
            dp[i] = std::min(dp[i], dp[j * j] + dp[i - j * j]);
        }
    }
    std::cout<<dp[n]<<std::endl;
}

