#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;
vector<bool> visited(51, false);
vector<vector<int>> graphs(51, vector<int>(51, 0));
unordered_map<int, int> nodeCount;

int bfs(int startIndex, string target, const vector<string>& words)
{
    queue<int> qu;
    qu.push(startIndex);
    visited[startIndex] = true;
    
    while(!qu.empty())
    {
        int index = qu.front();
        qu.pop();
        for (int i = 0; i < graphs[index].size(); ++i)
        {
            if (graphs[index][i] == 0)
            {
                continue;
            }
            
            if (visited[i] == true)
            {
                continue;
            }
            visited[i] = true;
            nodeCount[i] = nodeCount[index] + 1;
            if (words[i] == target)
            {
                return nodeCount[i];
            }
            qu.push(i);
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    words.insert(words.begin(), begin);
    
    // target이 있는지 확인
    auto it = find(words.begin(), words.end(), target);
    if (it == words.end())
    {
        return 0;
    }
    
    // 그래프 구성
    for(int i = 0; i < words.size(); ++i)
    {
        for(int j = 0; j < words.size(); ++j)
        {
            // 같은 경우 서로 연결로
            if (words[i] == words[j])
            {
                graphs[i][j] = 1;
                graphs[j][i] = 1;
                continue;
            }
            
            int diffCount = 0;
            for(int k = 0; k < words[i].size(); ++k)
            {
                if (words[i][k] != words[j][k])
                {
                    diffCount++;
                }
            }
            
            // 한단어만 다른경우 경로로 지정
            if (diffCount <= 1)
            {
                graphs[i][j] = 1;
                graphs[j][i] = 1;
            }
        }
    }
    
    
    return bfs(0, target, words);
}