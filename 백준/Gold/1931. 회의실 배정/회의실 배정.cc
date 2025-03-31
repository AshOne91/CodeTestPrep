#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::cin>>N;
    std::vector<std::pair<int, int>> timeList;
    for (int i = 0; i < N; ++i)
    {
        int start, end;
        std::cin>>start>>end;
        timeList.push_back({start, end});
    }
    
    std::sort(timeList.begin(), timeList.end(), [](const auto& left, const auto& right){
        if (left.second < right.second)
        {
            return left.second < right.second;
        }
        if (left.second == right.second)
        {
            return left.first < right.first;
        }
        return left.second < right.second;
    });
    
    int lastEndIndex = 0;
    int count = 1;
    for (int i = 1; i < N; ++i)
    {
        if (timeList[lastEndIndex].second <= timeList[i].first)
        {
            lastEndIndex = i;
            count++;
        }
    }
    std::cout<<count;
}