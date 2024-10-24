#include<iostream>
#include<unordered_map>
#include<string>

int main()
{
    std::ios::sync_with_stdio(false);  // 입출력 속도 최적화
    std::cin.tie(NULL);                // 입출력 묶음 해제
    std::cout.tie(NULL);                // 입출력 묶음 해제

    std::unordered_map<std::string, std::string> numByName;
    std::unordered_map<std::string, std::string> nameByNum;
    int N,M;
    std::cin>>N>>M;
    
    for(int i = 1; i <= N; ++i)
    {
        std::string name;
        std::cin>>name;
        numByName[name] = std::to_string(i);
        nameByNum[std::to_string(i)] = name;
    }
    
    for(int i = 0; i < M; ++i)
    {
        std::string str;
        std::cin>>str;
        if (numByName.find(str) != numByName.end())
        {
            std::cout<<numByName[str]<<"\n";
        }
        else if (nameByNum.find(str) != nameByNum.end())
        {
            std::cout<<nameByNum[str]<<"\n";
        }
    }
    return 0;
}