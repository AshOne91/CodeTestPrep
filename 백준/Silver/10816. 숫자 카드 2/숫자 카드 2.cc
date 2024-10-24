#include<iostream>
#include<unordered_map>

int main()
{
    std::ios::sync_with_stdio(false);  // 입출력 속도 최적화
    std::cin.tie(NULL);                // 입출력 묶음 해제
    std::cout.tie(NULL);                // 입출력 묶음 해제

    int N;
    std::cin>>N;
    std::unordered_map<int, int> numCnt;
    
    for(int i = 0; i < N; ++i)
    {
        int num;
        std::cin>>num;
        numCnt[num]++;
    }
    
    int M;
    std::cin>>M;
    for(int i = 0; i < M; ++i)
    {
        int num;
        std::cin>>num;
        std::cout<<numCnt[num]<<" ";
    }
    return 0;
}