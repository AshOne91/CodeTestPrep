#include<iostream>
#include<stack>

int main()
{
    std::ios::sync_with_stdio(false);  // 입출력 속도 최적화
    std::cin.tie(NULL);                // 입출력 묶음 해제
    std::cout.tie(NULL);                // 입출력 묶음 해제

    std::stack<int> st;
    int N;
    std::cin>>N;
    int num;
    for(int i = 0; i < N; ++i)
    {
        std::string command;
        std::cin>>command;
        if (command == "push")
        {
            std::cin>>num;
            st.push(num);
        }
        else if(command == "pop")
        {
            if (st.empty())
            {
                std::cout<<"-1"<<"\n";
            }
            else
            {
                std::cout<<st.top()<<"\n";
                st.pop();
            }
        }
        else if (command == "size")
        {
            std::cout<<st.size()<<"\n";
        }
        else if (command == "empty")
        {
            if (st.empty())
            {
                std::cout<<1<<"\n";
            }
            else
            {
                std::cout<<0<<"\n";
            }
        }
        else if (command == "top")
        {
            if (st.empty())
            {
                std::cout<<-1<<"\n";
            }
            else
            {
                std::cout<<st.top()<<"\n";
            }
        }
    }
    return 0;
}