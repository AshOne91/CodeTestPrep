#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
std::vector<int> firstPattern{1,2,3,4,5,1,2,3,4,5};
std::vector<int> secondPattern{2,1,2,3,2,4,2,5};
std::vector<int> thirdPattern{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    std::vector<int> cnt(3,0);
    for(int i = 0; i < answers.size(); ++i)
    {
        if (answers[i] == firstPattern[i % firstPattern.size()])
        {
            cnt[0]++;
        }
        if (answers[i] == secondPattern[i % secondPattern.size()])
        {
            cnt[1]++;
        }
        if (answers[i] == thirdPattern[i % thirdPattern.size()])
        {
            cnt[2]++;
        }
    }
    
    int maxValue = *max_element(cnt.begin(), cnt.end());
    vector<int> answer;
    for(int i = 0; i < cnt.size(); ++i)
    {
        if (cnt[i] == maxValue)
            answer.push_back(i + 1);
    }
    return answer;
}