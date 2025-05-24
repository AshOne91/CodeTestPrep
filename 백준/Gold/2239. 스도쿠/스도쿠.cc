#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<int>> board(9, std::vector<int>(9));

// 현재 위치에 num을 놓을 수 있는지 검사
bool isValid(int row, int col, int num)
{
    // 행 검사
    for (int i = 0; i < 9; ++i)
        if (board[row][i] == num)
            return false;

    // 열 검사
    for (int i = 0; i < 9; ++i)
        if (board[i][col] == num)
            return false;

    // 3x3 박스 검사
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[startRow + i][startCol + j] == num)
                return false;

    return true;
}

// 백트래킹으로 스도쿠를 푸는 함수
bool solve()
{
    for (int y = 0; y < 9; ++y)
    {
        for (int x = 0; x < 9; ++x)
        {
            if (board[y][x] == 0) // 빈칸이라면
            {
                for (int num = 1; num <= 9; ++num)
                {
                    if (isValid(y, x, num))
                    {
                        board[y][x] = num;
                        if (solve())
                            return true; // 다음 칸으로 진행
                        board[y][x] = 0; // 백트래킹
                    }
                }
                return false; // 1~9 중 넣을 수 있는 게 없으면 실패
            }
        }
    }
    return true; // 모든 칸이 채워졌다면 성공
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    // 입력 처리
    for (int i = 0; i < 9; ++i)
    {
        std::string input;
        std::cin >> input;
        for (int j = 0; j < 9; ++j)
        {
            board[i][j] = input[j] - '0';
        }
    }

    solve(); // 스도쿠 풀이 실행

    // 결과 출력
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
            std::cout << board[i][j];
        std::cout << '\n';
    }

    return 0;
}
