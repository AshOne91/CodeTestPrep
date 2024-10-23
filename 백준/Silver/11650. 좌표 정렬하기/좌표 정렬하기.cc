#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    std::ios::sync_with_stdio(false);  // 입출력 속도 최적화
    std::cin.tie(NULL);                // 입출력 묶음 해제
    std::cout.tie(NULL);
    
    int N;
    std::cin>>N;
    
    std::vector<std::pair<int/*x*/, int/*y*/>> sortedPoint;
    for (int i = 0; i < N; ++i)
    {
        int x, y;
        std::cin>>x>>y;
        sortedPoint.push_back({x, y});
    }
    
    std::sort(sortedPoint.begin(), sortedPoint.end(), [](auto& lhs, auto& rhs){
        if(lhs.first == rhs.first)
        {
            return lhs.second < rhs.second;
        }
        return lhs.first < rhs.first;
    });
    
    for(const auto& [x, y]:sortedPoint)
    {
        std::cout<<x<<" "<<y<<"\n";
    }
    
    return 0;
}