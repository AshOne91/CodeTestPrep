#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<int>> board(9, std::vector<int>(9));
std::vector<std::pair<int, int>> blanks; // 빈칸 위치 저장

// 현재 위치에 num을 놓을 수 있는지 검사
bool isValid(int row, int col, int num)
{
    for (int i = 0; i < 9; ++i)
    {
        if (board[row][i] == num) return false; // 행
        if (board[i][col] == num) return false; // 열
    }

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[startRow + i][startCol + j] == num)
                return false; // 3x3 박스

    return true;
}

// 백트래킹 함수: idx번째 빈칸을 채운다
bool solve(int idx)
{
    if (idx == blanks.size())
        return true; // 모든 빈칸을 다 채웠으면 성공

    int y = blanks[idx].first;
    int x = blanks[idx].second;

    for (int num = 1; num <= 9; ++num)
    {
        if (isValid(y, x, num))
        {
            board[y][x] = num;
            if (solve(idx + 1))
                return true;
            board[y][x] = 0; // 백트래킹
        }
    }
    return false; // 실패
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    // 입력 및 빈칸 수집
    for (int i = 0; i < 9; ++i)
    {
        std::string input;
        std::cin >> input;
        for (int j = 0; j < 9; ++j)
        {
            board[i][j] = input[j] - '0';
            if (board[i][j] == 0)
                blanks.emplace_back(i, j); // 빈칸 위치 저장
        }
    }

    solve(0); // 백트래킹 시작

    // 결과 출력
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
            std::cout << board[i][j];
        std::cout << '\n';
    }

    return 0;
}
