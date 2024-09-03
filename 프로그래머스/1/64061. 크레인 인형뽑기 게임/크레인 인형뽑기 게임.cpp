#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    // 보드스택을 준비
    vector<stack<int>> boardStack(board.size());
    // 뒤보드부터 셋팅
    for(int i = (board.size() - 1); 0 <= i; --i)
    {
        for(int j = 0; j < board[i].size(); ++j)
        {
            if (board[i][j] == 0)
            {
                continue;
            }
            boardStack[j].push(board[i][j]);
        }
    }
    
    stack<int> gamePang;
    for(int i = 0; i < moves.size(); ++i)
    {
        int stackIndex = moves[i] - 1;
        if (boardStack[stackIndex].empty())
        {
            continue;
        }
        int doll = boardStack[stackIndex].top();
        boardStack[stackIndex].pop();
        
        if (gamePang.empty())
        {
            gamePang.push(doll);
            continue;
        }
        
        if (gamePang.top() == doll)
        {
            gamePang.pop();
            answer += 2;
            continue;
        }
        
        gamePang.push(doll);
    }
    return answer;
}