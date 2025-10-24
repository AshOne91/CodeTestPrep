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

    int N, M;
    std::cin>>N>>M;
    std::vector<int> indegress(N + 1, 0);
    std::vector<std::vector<int>> graphs(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int from, to;
        std::cin>>from>>to;
        graphs[from].push_back(to);
        indegress[to]++;
    }

    std::queue<int> qu;
    for (int i = 1; i <= N; ++i)
    {
        if (indegress[i] == 0)
        {
            qu.push(i);
        }
    }

    while(!qu.empty())
    {
        int node = qu.front();
        qu.pop();
        std::cout<<node<<' ';
        for (int next_node : graphs[node])
        {
            indegress[next_node]--;
            if (indegress[next_node] == 0)
            {
                qu.push(next_node);
            }
        }
    }

    return 0;
}
