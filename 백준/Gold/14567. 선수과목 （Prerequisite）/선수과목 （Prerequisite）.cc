#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 문제 풀이 코드 작성
    int N, M;
    std::cin>>N>>M;
    std::vector<int> indegress(N + 1, 0);
    std::vector<std::vector<int>> graphs(N + 1);

    for (int i = 0; i < M; ++i)
    {
        int from, to;
        std::cin>>from>>to;
        graphs[from].push_back(to);
        ++indegress[to];
    }

    std::queue<int> qu;
    std::vector<int> result(N + 1, 0);
    for (int i = 1; i <= N; ++i)
    {
        if (indegress[i] == 0)
        {
            qu.push(i);
            result[i] = 1;
        }
    }

    while(!qu.empty())
    {
        int node = qu.front();
        qu.pop();

        for (int next_node : graphs[node])
        {
            result[next_node] = std::max(result[next_node],result[node] + 1);
            --indegress[next_node];
            if (indegress[next_node] == 0)
            {
                qu.push(next_node);
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        std::cout<<result[i]<<' ';
    }

    return 0;
}
