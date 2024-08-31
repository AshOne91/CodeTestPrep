#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    string num;
    unordered_map</*num*/int, /*count*/int> numCount;
    for (char ch : s)
    {     
        if (isdigit(ch)) 
        {
            num += ch;
        } 
        else if (!num.empty()) 
        {
            numCount[stoi(num)]++;
            num.clear();
        }   
    }
    
    std::vector<pair</*num*/int, /*count*/int>> sortNum(numCount.begin(), numCount.end());
  
    sort(sortNum.begin(), sortNum.end(), [](const pair<int,int>& lhs, const pair<int,int>& rhs){
        return lhs.second > rhs.second;
    });
    
    for(auto& kv : sortNum)
    {
        answer.push_back(kv.first);
    }
    
    return answer;
}