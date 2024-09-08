#include <string>
#include <cstring>
#include <vector>
#include <sstream> 
#include <unordered_map>

using namespace std;

vector<string> split(string str, char delimiter)
{
    vector<string> tokens;
    string token;
    
    stringstream ss(str);
    while(getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }
    tokens.push_back(token);
    
    return tokens;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map</*uid*/string,/*nick*/string> nickMap;
    for(int i = 0; i < record.size(); ++i)
    {
        vector<string> cmd = split(record[i], ' ');
        if(cmd[0] == "Enter")
        {
          nickMap[cmd[1]] = cmd[2];
        }
        else if(cmd[0] == "Change")
        {
            nickMap[cmd[1]] = cmd[2];
        }
    }
    
    for(int i = 0; i < record.size(); ++i)
    {
        vector<string> cmd = split(record[i], ' ');
        string result;
        if(cmd[0] == "Enter")
        {
            result += nickMap[cmd[1]];
            result += "님이 들어왔습니다.";
            answer.push_back(result);
        }
        else if(cmd[0] == "Leave")
        {
            result += nickMap[cmd[1]];
            result += "님이 나갔습니다.";
            answer.push_back(result);
        }
    }
    return answer;
}