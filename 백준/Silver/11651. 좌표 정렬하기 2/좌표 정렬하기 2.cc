#include<iostream>
#include<algorithm>
#include<vector>

int main()
{
    int N;
    std::cin>>N;
    
    std::vector<std::pair<int, int>> sortedList;
    for(int i = 0; i < N; ++i)
    {
        int x, y;
        std::cin>>x>>y;
        
        sortedList.push_back({x, y});
    }
    
    std::sort(sortedList.begin(), sortedList.end(),[](const auto& lhs, const auto& rhs){
        if (lhs.second == rhs.second)
        {
            return lhs.first < rhs.first;
        }
        return lhs.second < rhs.second;
    });
    
    for(const auto& [x, y] : sortedList)
    {
        std::cout<<x<<" "<<y<<"\n";
    }
    return 0;
}