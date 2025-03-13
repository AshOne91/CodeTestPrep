#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

std::unordered_set<int> board;

int main()
{
    std::ios_base::sync_with_stdio(false);;
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int M;
    std::cin>>M;
    for (int i = 0; i < M; ++i)
    {
        std::string command;
        int M;
        std::cin>>command;
        if (command == "add")
        {
            std::cin>>M;
            board.insert(M);
        }
        else if (command == "remove")
        {
            std::cin>>M;
            board.erase(M);
        }
        else if (command == "check")
        {
            std::cin>>M;
            if (board.find(M) != board.end())
            {
                std::cout<<1<<"\n";
            }
            else
            {
                std::cout<<0<<"\n";
            }
        }
        else if (command == "toggle")
        {
            std::cin>>M;
            auto it = board.find(M);
            if (it != board.end())
            {
                board.erase(it);
            }
            else
            {
                board.insert(M);
            }
        }
        else if (command == "all")
        {
            for (int i = 1; i < 21; ++i)
            {
                board.insert(i);
            }
        }
        else if (command == "empty")
        {
            board.clear();
        }
    }
}