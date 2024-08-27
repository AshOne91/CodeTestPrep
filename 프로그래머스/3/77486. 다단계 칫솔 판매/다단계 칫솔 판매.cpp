#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    unordered_map<string, string> parent;
    for(int i = 0; i < referral.size(); ++i)
    {
        parent[enroll[i]] = referral[i];
    }
    
    unordered_map<string, int> money;
    for(int i = 0; i < seller.size(); ++i)
    {
        string name = seller[i];
        int percent = int((amount[i] * 100) * 0.1);
        int remainAmount = ((amount[i] * 100) - percent);
        money[seller[i]] += remainAmount; 
        for(;;)
        {
            auto& parentName = parent[name];
            if (parentName == "-")
            {
                break;
            }
            remainAmount = percent - int(percent * 0.1);
            money[parentName] += remainAmount;
            percent = int(percent * 0.1);
            name = parentName;
            if (percent == 0)
            {
                break;
            }
        }
    }
    vector<int> answer;
    for(int i = 0; i < enroll.size(); ++i)
    {
        answer.push_back(money[enroll[i]]);
    }
    return answer;
}