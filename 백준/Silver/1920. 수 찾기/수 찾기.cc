#include<iostream>
#include<unordered_set>
int main()
{
    std::ios::sync_with_stdio(false);  // 입출력 속도 최적화
    std::cin.tie(NULL);                // 입출력 묶음 해제
    std::cout.tie(NULL);                // 입출력 묶음 해제

    int N;
    std::cin>>N;
    std::unordered_set<int> numList;
    for(int i = 0; i < N; ++i)
    {
        int num;
        std::cin>>num;
        numList.insert(num);
    }
    
    int M;
    std::cin>>M;
    for(int i = 0; i < M; ++i)
    {
        int num;
        std::cin>>num;
        if (numList.find(num) == numList.end())
        {
            std::cout<<0<<"\n";
        }
        else
        {
            std::cout<<1<<"\n";
        }
    }
    return 0;
}