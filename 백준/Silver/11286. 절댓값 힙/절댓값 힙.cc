#include<iostream>
#include<queue>
#include<vector>

int main()
{
    std::ios::sync_with_stdio(false);  // 입출력 속도 최적화
    std::cin.tie(NULL);                // 입출력 묶음 해제
    std::cout.tie(NULL);                // 입출력 묶음 해제
    
    auto cmp = [](int lhs, int rhs)
    {
        if (std::abs(lhs) == std::abs(rhs))
        {
            return lhs > rhs;
        }
        return std::abs(lhs) > std::abs(rhs);
    };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> minHeap(cmp);
    
    int N;
    std::cin>>N;
    
    for (int i = 0; i < N; ++i)
    {
        int num;
        std::cin>>num;
        if (num == 0)
        {
            if (minHeap.empty())
            {
                std::cout<<0<<"\n";
            }
            else
            {
                std::cout<<minHeap.top()<<"\n";
                minHeap.pop();
            }
        }
        else
        {
            minHeap.push(num);
        }
    }
}