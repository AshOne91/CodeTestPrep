#include <vector>
#include <cmath>

using namespace std;

bool checkSafe(int y, int x, const vector<int>& queenPos)
{
    for(int indexY = 0; indexY < y; ++indexY)
    {
        int currentX = queenPos[indexY];
        // 열 중복 체크와 대각선 체크
        if (currentX == x || abs(x - currentX) == abs(y - indexY))
        {
            return false;
        }
    }
    return true;
}

int CanPlace(int y, vector<int>& queenPos)
{
    int retval = 0;
    if(y == queenPos.size()) // 모든 행에 퀸을 배치한 경우
    {
        return 1;
    }
    for(int x = 0; x < queenPos.size(); ++x)
    {
        if(checkSafe(y, x, queenPos))
        {
            queenPos[y] = x;
            retval += CanPlace(y + 1, queenPos);
            queenPos[y] = -1; // 백트래킹
        }
    }
    return retval;
}

int solution(int n) {
    vector<int> queenPos(n, -1);
    return CanPlace(0, queenPos);
}