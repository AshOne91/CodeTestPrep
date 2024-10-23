#include<iostream>
#include<stack>

int main()
{
    int K;
    std::cin>>K;
    
    std::stack<int> st;
    for(int i = 0; i < K; ++i)
    {
        int num;
        std::cin>>num;
        
        if (num == 0)
        {
            st.pop();
        }else
        {
            st.push(num);
        }
    }
    
    int total = 0;
    while(!st.empty())
    {
        total += st.top();
        st.pop();
    }
    
    std::cout<<total<<std::endl;
    return 0;
}
