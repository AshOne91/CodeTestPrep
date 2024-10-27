#include<iostream>
#include<vector>

std::vector<int> dp(1001, 0);

int main()
{
    dp[1] = 1;
    dp[2] = 3;
    
    for(int i = 3; i <= 1000; ++i)
    {
        dp[i] = (dp[i - 1] + 2*dp[i - 2]) % 10007;
    }
    
    int n;
    std::cin>>n;
    std::cout<<dp[n]<<std::endl;
}