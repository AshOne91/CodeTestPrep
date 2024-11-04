#include<iostream>
#include<algorithm>
#include<vector>

int main()
{
    std::ios::sync_with_stdio(false);  // 입출력 속도 최적화
    std::cin.tie(NULL);                // 입출력 묶음 해제
    std::cout.tie(NULL);                // 입출력 묶음 해제
    
    int N;
    std::cin>>N;
    
    if (N == 0)
    {
        std::cout<<0;
        return 0;
    }
    
    std::vector<std::pair<int/*start*/, int/*end*/>> sortedList;
    for(int i = 0; i < N; ++i)
    {
        int start, end;
        std::cin>>start>>end;
        sortedList.push_back({start, end});
    }
    
    std::sort(sortedList.begin(), sortedList.end(), [](auto& lhs, auto& rhs){
        if (lhs.second == rhs.second)
        {
            return lhs.first < rhs.first;
        }
        return lhs.second < rhs.second;
    });
    
    int endTime = sortedList[0].second;
    int cnt = 1;
    for (int i = 1; i < N; ++i)
    {
        if (endTime <= sortedList[i].first)
        {
            cnt++;
            endTime = sortedList[i].second;
        }
    }
    std::cout<<cnt;
    return 0;
}