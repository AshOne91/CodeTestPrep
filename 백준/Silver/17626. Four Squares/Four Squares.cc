#include<iostream>
#include<vector>
#include<cmath>

std::vector<int> dp(50001, 0);

int main()
{
    int n;
    std::cin>>n;
    
    for (int i = 1; i * i <= dp.size(); ++i)
    {
        dp[i * i] = 1;
    }
    
    for (int i = 1; i <= n; i++)
	{
		int min = 10000;
		if (dp[i] != 1)
		{
			for (int j = 1; j <= std::sqrt(i); j++)
			{
				int a = dp[j * j] + dp[i - j * j];
				if (min > a)
				{
					min = a;
					dp[i] = a;
				}
			}
		}
	}
	std::cout << dp[n];
	return 0;
}
