#include<iostream>
#include<stack>

int main()
{
    int T;
    std::cin>>T;
    std::cin.ignore(); // 개행 문자를 무시
    
    for(int i = 0; i < T; ++i)
    {
        std::string str;
        std::getline(std::cin, str);
        std::stack<char> st;
        bool flag = false;
        for(auto ch : str)
        {
            if (ch == '(')
            {
                st.push(ch);
                continue;
            }
            
            if (ch == ')')
            {
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    flag = true;
                    break;
                }
            }
            else
            {
                flag = true;
                break;
            }
        }
        
        if (st.empty() && flag == false)
        {
            std::cout<<"YES"<<"\n";
        }
        else
        {
            std::cout<<"NO"<<"\n";
        }
    }
    return 0;
}