#include<iostream>
#include<vector>

int main()
{
    int N;
    std::cin>>N;
    
    std::vector<std::pair<int/*몸무게*/, int/*키*/>> peopleList;
    for(int i = 0; i < N; ++i)
    {
        int x, y;
        std::cin>>x>>y;
        peopleList.push_back({x, y});
    }
    
    std::vector<int> resultList(peopleList.size(), 1);
    for(int i = 0; i < peopleList.size(); ++i)
    {
        for(int j = 0; j < peopleList.size(); ++j)
        {
            if (i == j) continue;
            
            if (peopleList[i].first < peopleList[j].first &&
            peopleList[i].second < peopleList[j].second)
            {
                resultList[i]++;
            }
        }
    }
    
    for(auto result : resultList)
    {
        std::cout<<result<<" ";
    }
    return 0;
}