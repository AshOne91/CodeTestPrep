#include <iostream>
#include <vector>
#include <stack>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, E;
    std::cin>>N>>E;
    std::vector<std::vector<int>> graph(N+1);
    std::vector<bool> visited(N+1);

    for (int i = 0; i < E; ++i)
    {
        int a, b;
        std::cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    std::stack<int> st;
    st.push(1);
    visited[1] = true;

    int cnt = 0;
    while(!st.empty())
    {
        int node = st.top();
        st.pop();

        for (const auto& next_node : graph[node])
        {
            if (visited[next_node] == true)
            {
                continue;
            }
            st.push(next_node);
            visited[next_node] = true;
            cnt++;
        }
    }

    std::cout<<cnt;
}