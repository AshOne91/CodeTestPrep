// 입력받은 문자열을 반복문을 돌면서 알파벳일시 바로 출력해준다.
// 알파벳이 아닐시,
    // 만약 '('라면 스택에 넣어준다.
    //만약 '*'나 '/'(계산 우선순위 2번)라면 스택에서 스택이 빌때까지 '*'나 '/'일시 출력해주고 pop해준다.
    //그리고 현재 문자를 push해준다.
    //만약 '+'나 '-'(계산 우선순위 3번)라면 스택에서 스택이 빌때까지 '('가 아닐경우 출력해주고 pop해준다.
    //그리고 현재 문자를 push해준다.
    //만약 ')'(계산 우선순위 1번)라면 스택에서 스택이 빌때까지 '('가 아닐경우 출력해주고 pop해준다.
    //그리고 마지막으로 '('를 pop해준다.
// 스택에 문자들이 남아있을 경우 모두 출력해주고 pop해준다.
#include <iostream>
#include <string>
#include <vector>
#include <stack>
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::stack<char> st;
    std::string str;
    std::cin>>str;
    
    for (auto ch : str)
    {
        if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == '*' || ch == '/')
        {
            while(!st.empty() && (st.top() == '*' || st.top() == '/'))
            {
                std::cout<<st.top();
                st.pop();
            }
            st.push(ch);
        }
        else if (ch == '+' || ch == '-')
        {
            while(!st.empty() && st.top() != '(')
            {
                std::cout<<st.top();
                st.pop();
            }
            st.push(ch);
        }
        else if (ch == ')')
        {
            while(st.top() != '(')
            {
                std::cout<<st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            std::cout<<ch;
        }
    }
    while(!st.empty())
    {
        std::cout<<st.top();
        st.pop();
    }
}