#include<iostream>
#include<vector>

std::vector<std::pair<int, int>> dir{{-1, 0},{0, 1},{1, 0},{0, -1}};

int MaxDistBoard(int startY, int startX
, const std::vector<std::vector<int>>& boards
, std::vector<bool>& words)
{
    words[boards[startY][startX]] = true;
    int maxDist = 0;
    for (auto& [Y, X] : dir)
    {
        int nextY = startY + Y;
        int nextX = startX + X;
       if (nextY < 0 || nextY >= (int)boards.size()
       || nextX < 0 || nextX >= (int)boards[0].size())
        {
            continue;
        }
        
        if (words[boards[nextY][nextX]] == true)
        {
            continue;
        }
        maxDist = std::max(maxDist, MaxDistBoard(nextY, nextX, boards, words));
    }
    words[boards[startY][startX]] = false;
    return maxDist + 1;
}

int  main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int R, C;
    std::cin>>R>>C;
    
    std::vector<bool> words(26, false);
    std::vector<std::vector<int>> boards(R, std::vector<int>(C));
    for(int i = 0; i < R; ++i)
    {
        for(int j = 0; j < C; ++j)
        {
            char word;
            std::cin>>word;
            boards[i][j] = word - 'A';
        }
    }
    
    int result = MaxDistBoard(0, 0, boards, words);
    std::cout<<result;
}