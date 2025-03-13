#include<iostream>
#include<unordered_set>

int main()
{
    std::ios::sync_with_stdio(false);  // 입출력 속도 최적화
    std::cin.tie(NULL);                // 입출력 묶음 해제
    std::cout.tie(NULL);                // 입출력 묶음 해제

    std::unordered_set<int> setList;
    int M;
    std::cin>>M;
    for(int i = 0; i < M; ++i)
    {
        std::string command;
        std::cin>>command;
        
        int num;
        if (command == "add")
        {
            std::cin>>num;
            setList.insert(num);
        }
        else if(command == "remove")
        {
            std::cin>>num;
            setList.erase(num);
        }
        else if(command == "check")
        {
            std::cin>>num;
            if (setList.find(num) == setList.end())
            {
                std::cout<<0<<"\n";
            }
            else
            {
                std::cout<<1<<"\n";
            }
        }
        else if(command == "toggle")
        {
            std::cin>>num;
            if (setList.find(num) == setList.end())
            {
                setList.insert(num);
            }
            else
            {
                setList.erase(num);
            }
        }
        else if(command == "all")
        {
            for(int i = 1; i <= 20; ++i)
            {
                setList.insert(i);
            }
        }
        else if(command == "empty")
        {
            setList.clear();
        }
    }
    return 0;
}