#include<iostream>
#include<string>
#include<limits>
#include<vector>

std::vector<std::string> wb_board{
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
};
std::vector<std::string> bw_board{
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
};

int boardCheck(int startY, int startX, const std::vector<std::string>& board)
{
    int wbCnt = 0;
    int bwCnt = 0;
    for(int y = 0; y < 8; ++y)
    {
        for(int x = 0; x < 8; ++x)
        {
            if (wb_board[y][x] != board[startY + y][startX + x]) ++wbCnt;
            if (bw_board[y][x] != board[startY + y][startX + x]) ++bwCnt;
        }
    }
    
    return std::min(wbCnt, bwCnt);
}
int main()
{
    int y, x;
    std::cin>>y>>x;
    
    std::vector<std::string> board;
    for(int i = 0; i < y; ++i)
    {
        std::string str;
        std::cin>>str;
        board.push_back(str);
    }
    int minCnt = std::numeric_limits<int>::max();
    for(int i = 0; i < y - 7; ++i)
    {
        for(int j = 0; j < x - 7; ++j)
        {
            minCnt = std::min(boardCheck(i, j, board), minCnt);
        }
    }
    
    std::cout<<minCnt<<std::endl;
    return 0;
}