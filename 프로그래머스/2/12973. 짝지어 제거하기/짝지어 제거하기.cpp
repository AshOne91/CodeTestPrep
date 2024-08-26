#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 1;
    stack<char> st;
    for(auto& ch : s)
    {
        if (st.empty())
        {
            st.push(ch);
            continue;
        }
        if (st.top() == ch)
        {
            st.pop();
            continue;
        }
        st.push(ch);
    }
    if (!st.empty())
    {
        answer = 0;
    }

    return answer;
}