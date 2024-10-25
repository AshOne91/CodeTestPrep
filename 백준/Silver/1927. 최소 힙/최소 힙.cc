#include<iostream>
#include<functional>
#include<queue>

int main()
{
    std::ios::sync_with_stdio(false);  // 입출력 속도 최적화
    std::cin.tie(NULL);                // 입출력 묶음 해제
    std::cout.tie(NULL);                // 입출력 묶음 해제

    auto cmp = [](long long lhs, long long rhs){ return lhs > rhs;};
    std::priority_queue<long long, std::vector<long long>, decltype(cmp)> pq(cmp);
    
    int N;
    std::cin>>N;
    for(int i = 0; i < N; ++i)
    {
        long long num;
        std::cin>>num;
        if (num == 0)
        {
            if (pq.empty())
            {
                std::cout<<0<<"\n";
            }
            else
            {
                std::cout<<pq.top()<<"\n";
                pq.pop();
            }
        }
        else
        {
            pq.push(num);
        }
    }
    return 0;
}