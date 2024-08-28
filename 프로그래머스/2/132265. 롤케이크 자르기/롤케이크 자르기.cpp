#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> totalCount;
    unordered_map<int, int> remainCount;
    
    for(int i = 0; i < topping.size(); ++i)
    {
        totalCount[topping[i]]++;
    }
    for(int i = 0; i < topping.size(); ++i)
    {
        totalCount[topping[i]]--;
        if (totalCount[topping[i]] == 0)
        {
            totalCount.erase(topping[i]);
        }
        remainCount[topping[i]]++;
        if(totalCount.size() == remainCount.size())
        {
            ++answer;
        }
    }
    
    return answer;
}