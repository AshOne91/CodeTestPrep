#include<iostream>
#include<queue>

int main()
{
    std::queue<int> qu;
    
    int N;
    std::cin>>N;
    int num;
    for(int i = 0; i < N; ++i)
    {
        std::string command;
        std::cin>>command;
        
        if (command == "push")
        {
            std::cin>>num;
            qu.push(num);
        }
        else if (command == "pop")
        {
            if (qu.empty())
            {
                std::cout<<-1<<"\n";
            }
            else
            {
                std::cout<<qu.front()<<"\n";
                qu.pop();
            }
        }
        else if (command == "size")
        {
            std::cout<<qu.size()<<"\n";
        }
        else if (command == "empty")
        {
            if (qu.empty())
            {
                std::cout<<1<<"\n";
            }
            else
            {
                std::cout<<0<<"\n";   
            }
        }
        else if (command == "front")
        {
            if (qu.empty())
            {
                std::cout<<-1<<"\n";
            }
            else
            {
                std::cout<<qu.front()<<"\n";
            }
        }
        else if (command == "back")
        {
            if (qu.empty())
            {
                std::cout<<-1<<"\n";
            }
            else
            {
                std::cout<<qu.back()<<"\n";
                
            }
        }
    }
    return 0;
}