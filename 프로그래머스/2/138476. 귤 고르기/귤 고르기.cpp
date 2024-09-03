#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    
    unordered_map<int/*size*/,int/*count*/> tangerineCount;
    for(int i = 0; i < tangerine.size(); ++i)
    {
        tangerineCount[tangerine[i]]++;
    }
    
    vector<pair<int/*size*/, int/*count*/>> sortedTangerine(tangerineCount.begin(), tangerineCount.end());
    
    sort(sortedTangerine.begin(), sortedTangerine.end(),[](const pair<int, int> lhs, const pair<int, int> rhs)
    {
        //양이 많은거 순으로
        return lhs.second > rhs.second;
    });

    
    int answer = 0;
    for(auto& value : sortedTangerine)
    {
        ++answer;
        k -= value.second;
        if (k <= 0)
        {
            break;
        }
    }
    
    return answer;
}