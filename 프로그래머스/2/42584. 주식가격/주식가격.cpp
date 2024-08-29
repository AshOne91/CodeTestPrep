#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    
    stack<int> indexSt;
        
    indexSt.push(0);
    for(int i = 1; i < prices.size(); ++i)
    {
        if (indexSt.empty())
        {
            indexSt.push(i);
            continue;
        }
        if (prices[indexSt.top()] <= prices[i])
        {
            indexSt.push(i);
            continue;
        }
        
        while(!indexSt.empty() && prices[indexSt.top()] > prices[i])
        {
            int compareIndex = indexSt.top();
            answer[compareIndex] = (i - compareIndex);
            indexSt.pop();
        }
        indexSt.push(i);
    }
    
    while(!indexSt.empty())
    {
        int compareIndex = indexSt.top();
        answer[compareIndex] = ((prices.size() - 1) - compareIndex);
        indexSt.pop();
    }
    
    return answer;
}