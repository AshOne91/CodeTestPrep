#include<iostream>
#include<vector>

std::vector<long long> dp(101, 0);

int main()
{
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= 100; ++i)
    {
        dp[i] = dp[i - 2] + dp[i - 3];
    }
    
    int testCase;
    std::cin>>testCase;
    for (int i = 0; i < testCase; ++i)
    {
        int n;
        std::cin>>n;
        std::cout<<dp[n]<<std::endl;
    }
    return 0;
}