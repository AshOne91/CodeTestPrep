#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<string> split(string str, char delimiter)
{
    string s;
    stringstream ss(str);
    vector<string> v;
    while (getline(ss, s, delimiter))
    {
        v.push_back(s);
    }
    return v;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    // k회 이상일 시 정지 메일
    unordered_map<string, int> reportCount;
    unordered_map<string, unordered_set</*reportUser*/string>> reportUser;
    unordered_map<string, unordered_set</*reportedUser*/string>> reportedUser;
    for (int i = 0; i < report.size(); ++i)
    {
        vector<string> cmd = split(report[i], ' ');
        //중복 신고 안됨
        if (reportUser[cmd[1]].find(cmd[0]) != reportUser[cmd[1]].end())
        {
            continue;
        }
        // 리포트 카운트와 리포트 유저를 기록
        reportUser[cmd[1]].insert(cmd[0]);
        reportedUser[cmd[0]].insert(cmd[1]);
        reportCount[cmd[1]]++;
    }
    for (int i = 0; i < id_list.size(); ++i)
    {
        int mailCount = 0;
        // 리포트한 유저를 순회
        for (auto& value : reportedUser[id_list[i]])
        {
            if (reportCount[value] >= k)
            {
                mailCount++;
            }
        }
        answer.push_back(mailCount);
    }

    return answer;
}