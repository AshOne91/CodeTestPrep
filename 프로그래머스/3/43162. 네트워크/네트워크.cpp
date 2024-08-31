#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n, false);
    int count = 0;
    for(int i = 0; i < computers.size(); ++i)
    {
        if (visited[i] == true)
        {
            continue;
        }
        
        
        // i번째 컴퓨터
        ++count;
        stack</*index*/int> st;
        st.push(i);
        visited[i] = true;
        
        while(!st.empty())
        {
            int index = st.top();
            st.pop();
            
            for(int j = 0; j < computers[i].size(); ++j)
            {
                // 연결 아님
                if (computers[index][j] == 0)
                {
                    continue;
                }
                
                //연결은 되었으나 방문했음
                if (visited[j] == true)
                {
                    continue;
                }
                
                //방문처리
                visited[j] = true;
                st.push(j);
            }
        }
    }

    return count;
}