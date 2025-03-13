#include <iostream>
#include <vector>
#include <string>

std::vector<int> board(21, 0);

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
        int num;
        std::cin>>command;
        if (command == "add")
        {
            std::cin>>num;
            board[num] = 1;
        }
        else if (command == "remove")
        {
            std::cin>>num;
            board[num] = 0;
        }
        else if (command == "check")
        {
            std::cin>>num;
            std::cout<<board[num]<<"\n";
        }
        else if (command == "toggle")
        {
            std::cin>>num;
            board[num] = !board[num];
        }
        else if (command == "all")
        {
            for (int j = 1; j < 21; ++j)
            {
                board[j] = 1;
            }
        }
        else if (command == "empty")
        {
            for (int j = 1; j < 21; ++j)
            {
                board[j] = 0;
            }
        }
    }
}