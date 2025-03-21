#include <iostream>
#include <vector>
int main()
{
    int n;
    std::cin>>n;
    std::vector<int> dp(1001, 0);
    dp[1] = 1; // 2X1
    dp[2] = 2; // 2X2 
    for (int i = 3 ; i <= n; ++i)
        dp[i] = (dp[i - 1] + dp[i - 2])%10007;
    std::cout<<dp[n]<<'\n';
}