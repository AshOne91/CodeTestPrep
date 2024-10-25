#include<iostream>
#include<vector>
#include<stack>

int main()
{
    int count;
    std::cin>>count;
    std::vector<std::vector<int>> adjustList(count + 1);
    std::vector<bool> visited(count + 1, false);
    
    int n;
    std::cin>>n;
    for(int i = 0; i < n; ++i)
    {
        int node1, node2;
        std::cin>>node1>>node2;
        adjustList[node1].push_back(node2);
        adjustList[node2].push_back(node1);
    }
    
    int networkCount = 0;
    std::stack<int> st;  
    st.push(1);
    visited[1] = true;
    while(!st.empty())
    {
        int currentIndex = st.top();
        st.pop();
        
        for (auto nextIndex : adjustList[currentIndex])
        {
            if (visited[nextIndex] == true)
            {
                continue;
            }
            visited[nextIndex] = true;
            st.push(nextIndex);
            networkCount++;
        }
    }
    
    std::cout<<networkCount<<std::endl;
    
    return 0;
}