#include<iostream>
#include<vector>

int main()
{
    std::ios::sync_with_stdio(false);  // 입출력 속도 최적화
    std::cin.tie(NULL);                // 입출력 묶음 해제
    std::cout.tie(NULL);                // 입출력 묶음 해제

    int N, M;
    std::cin>>N>>M;
    
    std::vector<int> numList(N + 1, 0);
    for(int i = 1; i <= N; ++i)
    {
        int num;
        std::cin>>num;
        numList[i] = numList[i-1] + num;
    }
    
    for(int k = 0; k < M; ++k)
    {
        int i, j;
        std::cin>>i>>j;
        int sum = numList[j] - numList[i - 1];
        std::cout<<sum<<"\n";
    }
    return 0;
}