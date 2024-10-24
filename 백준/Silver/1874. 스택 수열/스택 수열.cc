#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<string>

int main()
{
    int n;
    std::cin>>n;
    std::stack<int> st;
    std::vector<char> result;
    bool flag = false;
    int curNum = 0;
    st.push(curNum++);
    for (int i = 0; i < n; ++i)
    {
        int num;
        std::cin>>num;
        while (st.top() < num)
        {
            st.push(curNum++);
            result.push_back('+');
        }
        if (st.top() == num)
        {
            st.pop();
            result.push_back('-');
        }
        else
        {
            flag = true;
            break;
        }
    }
    
    if (flag == true)
    {
        std::cout<< "NO"<<"\n";
    }
    else
    {
        for (auto ch : result)
        {
            std::cout<<ch<<"\n";
        }
    }
    return 0;
}