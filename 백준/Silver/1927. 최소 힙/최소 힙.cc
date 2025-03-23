#include <iostream>
#include <queue>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::cin>>N;
    auto cmp = [](int& left, int& right)
    {
          return left > right;  
    };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < N; ++i)
    {
        int x;
        std::cin>>x;
        if (x == 0)
        {
            if (pq.empty())
            {
                std::cout<<0<<'\n';
                continue;
            }
            std::cout<<pq.top()<<'\n';
            pq.pop();
            continue;
        }
        pq.push(x);
    }
}