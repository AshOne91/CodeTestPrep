#include<iostream>
#include<queue>
#include<vector>

int main()
{
    int N, K;
    std::cin>>N>>K;
    std::queue<int> qu;
    for(int i = 0; i < N; ++i)
    {
        qu.push(i + 1);
    }
    
    std::vector<int> resultList;
    while(!qu.empty())
    {
        for(int i = 0; i < K-1; ++i)
        {
            int num = qu.front();
            qu.pop();
            qu.push(num);
        }
        
        resultList.push_back(qu.front());
        qu.pop();
    }
    
    std::cout<<"<";
    for(int i = 0; i < resultList.size() - 1; ++i)
    {
        std::cout<<resultList[i]<<", ";
    }
    if (resultList.size() > 0)
    {
        std::cout<<resultList[resultList.size()-1];
    }
    std::cout<<">";
    return 0;
}