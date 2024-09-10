#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

// 오름차순으로 정렬되어야 되서
map<string, int> combiCount;

void combination(string src, string dst, int depth)
{
    if (dst.size() == depth)
    {
        combiCount[dst]++;
        return;
    }
    
    for (int i = 0; i < src.size(); ++i)
    {
        combination(src.substr(i+1), dst+src[i], depth);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(auto& order : orders)
    {
        sort(order.begin(), order.end());
    }
    
    for(auto num : course)
    {
        for(auto& order : orders)
        {
            combination(order, "", num);
        }
        
        int maxOrder = 0;
        for (auto& [combi, count] :  combiCount)
        {
            maxOrder = max(maxOrder, count);
        }
        
        for (auto& [combi, count] :  combiCount)
        {
            if (maxOrder >= 2 && count == maxOrder)
            {
                answer.push_back(combi);
            }
        }
        
        combiCount.clear();
    }
    
    //정렬시 사전순으로 됨
    sort(answer.begin(), answer.end());
    
    return answer;
}