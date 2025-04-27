#include <iostream>
#include <vector>

int total = 0;

bool isSafe(int x, int y, const std::vector<int>& board)
{
    for (int i = 0; i < x; ++i)
    {
        // Same column or diagonal
        if (board[i] == y || std::abs(board[i] - y) == std::abs(i - x))
        {
            return false;
        }
    }
    return true;
}

void NQueen(int x, int N, std::vector<int>& board)
{
    if (x == N)
    {
        ++total;
        return;
    }
    
    for (int i = 0; i < N; ++i)
    {
        if (isSafe(x, i, board))
        {
            board[x] = i;
            NQueen(x + 1, N, board); 
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::cin >> N;
    std::vector<int> board(N, 0);
    NQueen(0, N, board);
    std::cout << total;
}
