#include <string>
#include <vector>
#include <queue>

using namespace std;

struct point
{
    int y = -1;
    int x = -1;
    int distance = -1;
};

point FindStartPosition(char start, const vector<string>& maps)
{
    for(int i = 0; i < maps.size(); ++i)
    {
        for(int j = 0; j < maps[i].size(); ++j)
        {
            if (maps[i][j] == start)
            {
                return {i, j, 0};
            }
        }
    }
    return {-1, -1, -1};
}

bool CanMove(int y, int x, const vector<string>& maps)
{
    if (x < 0 || x >= maps[0].size())
    {
        return false;
    }
    if (y < 0 || y >= maps.size())
    {
        return false;
    }
    if (maps[y][x] == 'X')
    {
        return false;
    }
    return true;
}

vector<pair<int, int>> test = {/*상*/{-1, 0},/*하*/{1, 0},/*좌*/{0, -1},/*우*/{0, 1}};

int bfs(char start, char end, const vector<string>& maps)
{
    int visited[101][101] = {false,};
    queue<point> q;
    auto startPos = FindStartPosition(start, maps);
    q.push(startPos);
    visited[startPos.y][startPos.x] = true;
    
    while(!q.empty())
    {
        auto pos = q.front();
        q.pop();
        
        for (auto& testPos : test)
        {
            int checkY = pos.y + testPos.first;
            int checkX = pos.x + testPos.second;

            // 벽이 아님
            if (CanMove(checkY, checkX, maps) == true)
            {
                if (visited[checkY][checkX] == true)
                {
                    continue;
                }
                // end 포지션임
                if (maps[checkY][checkX] == end)
                {
                    return pos.distance + 1;
                }
                // 방문하지 않음
                point newP;
                newP.x = checkX;
                newP.y = checkY;
                newP.distance = pos.distance + 1;
                visited[checkY][checkX] = true;
                q.push(newP);
            }
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    
    int distance = bfs('S', 'L', maps);
    if (distance == -1)
    {
        return -1;
    }
    answer += distance;
    
    distance = bfs('L', 'E', maps);
    if (distance == -1)
    {
        return -1;
    }
    answer += distance;
    
    return answer;
}