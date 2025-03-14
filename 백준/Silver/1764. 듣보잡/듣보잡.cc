#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N; // 듣도 못한 사람의 수
    int M; // 보도 못한 사람의 수
    std::cin>>N>>M;
    std::unordered_map<std::string,int> mamber_map;
    
    // 둘째 줄부터 N개의 줄에 걸쳐 듣도 못한 사람의 이름
    for (int i = 0; i < N; ++i)
    {
        std::string str;
        std::cin>>str;
        mamber_map[str]++;
    }
    
    for (int i = 0; i < M; ++i)
    {
        std::string str;
        std::cin>>str;
        mamber_map[str]++;
    }
    
    std::vector<std::pair<std::string,int>> mamberList(mamber_map.begin(), mamber_map.end());
    std::sort(mamberList.begin(), mamberList.end(), 
              [](const std::pair<std::string, int>& left
                 , const std::pair<std::string, int>& right){
        return left.first < right.first;
    });
    
    std::vector<std::string> results;
    for(const auto& value : mamberList)
    {
        if (value.second == 2)
        {
            results.push_back({value.first});
        }
    }
    std::cout<<results.size()<<std::endl;
    for(const auto& result : results)
    {
        std::cout<<result<<"\n";
    }
}