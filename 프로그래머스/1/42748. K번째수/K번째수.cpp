#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); ++i)
    {
        vector<int> tempArray(array.begin()+(commands[i][0]-1), array.begin() + commands[i][1]);
        std::sort(tempArray.begin(), tempArray.end());
        answer.push_back(*(tempArray.begin() + (commands[i][2] - 1)));
    }
    
    return answer;
}