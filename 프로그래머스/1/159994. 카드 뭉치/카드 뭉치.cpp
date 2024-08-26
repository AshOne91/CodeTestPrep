#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    queue<string> cardOneQ;
    queue<string> cardTwoQ;
    queue<string> cardGoalQ;
    
    for(auto value : cards1)
    {
        cardOneQ.push(value);
    }
    for(auto value : cards2)
    {
        cardTwoQ.push(value);
    }
    for(auto value : goal)
    {
        cardGoalQ.push(value);
    }
    
    while(!cardGoalQ.empty())
    {
        auto value = cardGoalQ.front();
        
        if ((!cardOneQ.empty()) && (cardOneQ.front() == value))
        {
            cardOneQ.pop();
            cardGoalQ.pop();
            continue;
        }
        if((!cardTwoQ.empty()) && (cardTwoQ.front() == value))
        {
            cardTwoQ.pop();
            cardGoalQ.pop();
            continue;
        }
        break;
    }
    
    return cardGoalQ.empty() ? "Yes":"No";
}