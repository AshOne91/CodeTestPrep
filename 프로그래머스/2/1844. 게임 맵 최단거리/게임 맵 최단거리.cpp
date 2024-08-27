#include<vector>
#include<queue>
using namespace std;

bool CanMove(int indexY, int indexX, const vector<vector<int>>& maps)
{
    if (indexY < 0 || indexY >= maps.size())
    {
        return false;
    }
    if (indexX < 0 || indexX >= maps[0].size())
    {
        return false;
    }
    if (maps[indexY][indexX] == 0)
    {
        return false;
    }
    return true;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    vector<pair<int, int>> road{/*상*/{-1,0},/*하*/{1,0},/*좌*/{0,-1},/*우*/{0,1}};
    vector<vector<bool>> visited(maps.size(),vector<bool>(maps[0].size(), false));
    vector<vector<int>> count(maps.size(),vector<int>(maps[0].size(), 0));
    
    int startY = 0;
    int startX = 0;
    int endY = maps.size() - 1;
    int endX = maps[0].size() - 1;
    
    queue<pair</*y*/int, /*x*/int>> q;
    visited[startY][startX] = true;
    count[startY][startX]++;
    q.push({startY,startX});
    
    while(!q.empty())
    {
        auto node = q.front();
        q.pop();
        if (node.first == endY 
            && node.second == endX)
        {
            answer = count[node.first][node.second];
            break;
        }
        
        for(auto& nextRoad : road)
        {
            int nextY = node.first - nextRoad.first;
            int nextX = node.second - nextRoad.second;
            if (!CanMove(nextY, nextX, maps))
            {
                continue;
            }
            if (visited[nextY][nextX] == true)
            {
                continue;
            }
            visited[nextY][nextX] = true;
            count[nextY][nextX] = int(count[node.first][node.second] + 1);
            q.push({nextY,nextX});
        }
    }
    
    return (answer != 0)?answer:-1;
}