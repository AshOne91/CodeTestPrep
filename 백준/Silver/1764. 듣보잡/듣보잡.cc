#include<iostream>
#include<unordered_set>
#include<algorithm>

int main()
{
    int N, M;
    std::cin>>N>>M;
    
    std::unordered_set<std::string> nList;
    for (int i = 0; i < N; ++i)
    {
        std::string str;
        std::cin>>str;
        nList.insert(str);
    }

    std::vector<std::string> result;
    for (int i = 0; i < M; ++i)
    {
        std::string str;
        std::cin>>str;
        if (nList.find(str) != nList.end())
        {
            result.push_back(str);
        }
    }
    std::sort(result.begin(), result.end());
    
    std::cout<<result.size()<<std::endl;
    for(auto& value : result)
    {
        std::cout<<value<<std::endl;
    }
    return 0;
}