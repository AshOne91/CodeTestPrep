#include<iostream>
#include<vector>
int N;
int total;
std::vector<int> board(16, -1);

bool check(int level)
{
    for (int i = 0; i < level; ++i)
    {
        if (board[i] == board[level] || abs(board[level] - board[i]) == level - i)
        {
            return false;
        }
    }
    return true;
}

void NQueen(int x)
{
    if (x == N)
    {
        total++;
    }
    else
    {
        for (int i = 0; i < N; ++i)
        {
            board[x] = i;
            if (check(x))
            {
                NQueen(x + 1);
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cin>>N;
    NQueen(0);
    std::cout<<total;
}