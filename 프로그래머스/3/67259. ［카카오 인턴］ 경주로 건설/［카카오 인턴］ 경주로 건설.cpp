#include <cstring>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int STRAIGHT_COST = 100;
const int CORNER_COST = 600;
const int MAX_SIZE = 26;
const int INF = numeric_limits<int>::max();

struct Path
{
  int y, x, direction;  
};

bool isValid(int y, int x, int size)
{
    return y >= 0 && y < size && x >= 0 && x < size;
}

int solution(vector<vector<int>> board) {
    int boardSize = static_cast<int>(board.size());
    int dist[MAX_SIZE][MAX_SIZE][4];
    memset(dist, -1, sizeof(dist));
    queue<Path> q;
    
    q.push({0, 0, 1});
    q.push({0, 0, 3});
    
    dist[0][0][1] = 0;
    dist[0][0][3] = 0;
    
    while(!q.empty())
    {
        auto [y, x, dir] = q.front();
        q.pop();
        
        int lastCost = dist[y][x][dir];
        
        for(int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (isValid(ny, nx, boardSize) == false || board[ny][nx] == 1)
            {
                continue;
            }
            
            int newCost = lastCost + (i == dir ? STRAIGHT_COST : CORNER_COST);
            
            if (dist[ny][nx][i] == -1 || dist[ny][nx][i] > newCost)
            {
                dist[ny][nx][i] = newCost;
                q.push({ny, nx, i});
            }
            
        }
    }
    int answer = INF;
    for (int i = 0; i < 4; ++i)
    {
        if (dist[boardSize - 1][boardSize - 1][i] != -1)
        {
            answer = min(answer, dist[boardSize - 1][boardSize - 1][i]);
        }
    }
    
    return answer == INF ? -1 : answer;
}