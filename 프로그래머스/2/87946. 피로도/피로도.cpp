#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int maxDepth = 0;
void checkDungeon(int tiredPoint
, int index
, int depth
, const vector<vector<int>>& dungeons
, unordered_map<int, bool>& visited)
{
    // 최소입장 피로도
    if (tiredPoint < dungeons[index][0])
    {
        return;
    }
    tiredPoint -= dungeons[index][1];
    if (maxDepth < depth)
    {
        maxDepth = depth;
    }
    for(int i = 0; i < dungeons.size(); ++i)
    {
        if (visited[i] == true)
        {
            continue;
        }
        visited[i] = true;
        checkDungeon(tiredPoint, i, depth + 1, dungeons, visited);
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    std::unordered_map<int, bool> visited;
    for(int i = 0; i < dungeons.size(); ++i)
    {
        visited[i] = true;
        checkDungeon(k, i, 1, dungeons, visited);
        visited[i] = false;
    }
    return maxDepth;
}