#include <iostream>
#include <vector>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N, M;
    std::cin>>N>>M;
    std::vector<std::vector<int>> graph(N+1);
    std::vector<bool> visited(N+1, false);
    
    for (int i = 0; i < M; ++i)
    {
        int from, to;
        std::cin>>from>>to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    std::stack<int> st;
    int result = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (visited[i] == true)
        {
            continue;
        }
        result++;
        st.push(i);
        visited[i] = true;
        
        while(!st.empty())
        {
            int currentNode = st.top();
            st.pop();
            
            for (auto nearNode : graph[currentNode])
            {
                if (visited[nearNode] == true)
                {
                    continue;
                }
                visited[nearNode] = true;
                st.push(nearNode);
            }
        }
    }
    
    std::cout<<result;
}