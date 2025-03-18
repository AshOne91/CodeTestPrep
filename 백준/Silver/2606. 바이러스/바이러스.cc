#include <iostream>
#include <stack>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);
    
    int N;
    std::cin>>N;
    std::vector<std::vector<int>> graphs(N + 1);
    std::vector<bool> visited(N + 1, false);
    
    int T;
    std::cin>>T;
    
    for (int i = 0; i < T; ++i)
    {
        int from, to;
        std::cin>>from>>to;
        graphs[from].push_back(to);
        graphs[to].push_back(from);
    }
    
    int count = 0;
    std::stack<int> st;
    st.push(1);
    visited[1] = true;
    
    
    while(!st.empty())
    {
        int i = st.top();
        st.pop();
        
        for (auto nodeIndex : graphs[i])
        {
            if (visited[nodeIndex] == true)
                continue;
            
            count++;
            visited[nodeIndex] = true;
            st.push(nodeIndex);
        }
    }
    
    std::cout<<count<<"\n";
}