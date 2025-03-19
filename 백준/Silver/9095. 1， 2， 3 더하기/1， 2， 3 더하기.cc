#include <iostream>
#include <vector>
// 이거 답지봄
std::vector<int> sumDP(12, 0);
int main()
{
    sumDP[1] = 1;
    sumDP[2] = 2;
    sumDP[3] = 4;
    for (int i = 4; i < 11; ++i)
        sumDP[i] = sumDP[i - 3] + sumDP[i - 2] + sumDP[i - 1];
    int n;
    std::cin>>n;
    for (int i = 0; i < n; ++i)
    {
        int t;
        std::cin>>t;
        std::cout<<sumDP[t]<<'\n';
    }
}