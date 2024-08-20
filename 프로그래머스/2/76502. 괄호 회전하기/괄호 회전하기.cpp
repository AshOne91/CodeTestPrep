#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

unordered_map<char, char> twopair = {{'(',')'},{'[',']'},{'{','}'}};

int Check(string& s, int index)
{
    stack<char> checkStack;
    for(int i = 0; i < s.size(); ++i)
    {
        char ch = s[(index + i)%s.size()];
        if (twopair.find(ch) == twopair.end())
        {
            if (checkStack.empty() == true)
            {
                return 0;
            }
            if (twopair[checkStack.top()] != ch)
            {
                return 0;
            }
            checkStack.pop();
        }
        else
        {
            checkStack.push(ch);
        }
    }
    if (checkStack.empty() == false)
    {
        return 0;
    }
    
    return 1;
}

int solution(string s) {
    int answer = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        answer += Check(s, i);
    }
    return answer;
}