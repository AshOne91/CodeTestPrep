#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    unordered_map</*stage*/int, /*count*/int> peopleCount;    
    for(auto& stage:stages)
    {
        peopleCount[stage]++;
    }
    
    
    
    vector<pair</*stage*/int, /*failureRate*/float>> sortedFailure;
    // 전체 인원 수
    //if peopleNum = stages.count();
    // 누적 도달 인원 수
    int arriveCount = 0;
    // 올 스테이지 클리어 인원수
    if (peopleCount.find(N+1) != peopleCount.end())
    {
        // 누적해야 되기 때문에
        arriveCount = peopleCount[N+1];
    }

    for(int i = N; 0 < i; --i)
    {
        //스테이지에 도달한 플레이어 수
        float failureRate = 0.0f;
        arriveCount = peopleCount[i] + arriveCount;
        // 스테이지 도달 유저가 없는 경우 스테이지의 실패율 0
        if (arriveCount == 0)
        {
            sortedFailure.push_back({i, failureRate});
            continue;
        }
        failureRate = float((float)peopleCount[i] / (float)arriveCount);
        sortedFailure.push_back({i, failureRate});
    }
    
    // 실패율이 높은 스테이지부터 내림차순
    // 만약 실패율이 같은 스테이지가 있다면 작은 번호의 스테이지 먼저 오도록
    sort(sortedFailure.begin(), sortedFailure.end(),[](const pair<int, float>& lhs, const pair<int, float>& rhs)
         {
             if (lhs.second == rhs.second)
             {
                 return lhs.first < rhs.first;
             }
             return lhs.second > rhs.second;
         });
    
    for(auto& stageInfo : sortedFailure)
    {
        answer.push_back(stageInfo.first);
    }
    
    return answer;
}