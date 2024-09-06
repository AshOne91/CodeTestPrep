#include <string>
#include <unordered_map>
#include <set>

using namespace std;

unordered_map<char, pair<int, int>> dirByCmd{{'U',{ 0, 1}},{'D',{0, -1}},{'R',{1, 0}},{'L',{-1, 0}}};

bool CanMove(int moveX, int moveY, int currentPosX, int currentPosY)
{
    int nextPosX = currentPosX + moveX;
    int nextPosY = currentPosY + moveY;
    // x 범위 체크
    if (nextPosX < -5 || nextPosX > 5)
    {
        return false;
    }
    // y 범위 체크
    if (nextPosY < -5 || nextPosY > 5)
    {
        return false;
    }
    return true;
}

int solution(string dirs) {
    int answer = 0;
    pair<int, int> currentPos{0,0};
    set<pair<pair<int, int>, pair<int, int>>> visitedPaths; // 경로를 저장하는 set
    
    for(auto& dir: dirs)
    {
        // 경계 체크(움직임 무시)
        if (!CanMove(dirByCmd[dir].first, dirByCmd[dir].second, currentPos.first, currentPos.second))
        {
            continue;
        }
        
        // 다음 위치 계산
        int nextPosX = currentPos.first + dirByCmd[dir].first;
        int nextPosY = currentPos.second + dirByCmd[dir].second;
        
        // 이동 경로를 저장 (양방향 모두)
        pair<int, int> nextPos = {nextPosX, nextPosY};
        if (visitedPaths.find({currentPos, nextPos}) == visitedPaths.end() && 
            visitedPaths.find({nextPos, currentPos}) == visitedPaths.end())
        {
            answer++;
            visitedPaths.insert({currentPos, nextPos});
            visitedPaths.insert({nextPos, currentPos});
        }
        
        // 현재 위치 갱신
        currentPos = nextPos;
    }
    
    return answer;
}