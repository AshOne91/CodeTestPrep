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
    if (!(cin >> N >> M)) return 0;

    std::vector<std::vector<std::pair<int, int>>> graphs(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int from, to, cost;
        cin >> from >> to >> cost; // 입력 추가
        graphs[from].push_back({to, cost});
        graphs[to].push_back({from, cost});
    }

    std::vector<bool> visited(N + 1, false);

    auto cmp = [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs)
    {
        return lhs.second > rhs.second;
    };

    std::priority_queue<std::pair<int,int>,
                        std::vector<std::pair<int,int>>,
                        decltype(cmp)> pq(cmp);

    long long total_cost = 0;

    // 모든 컴포넌트 처리
    for (int start = 1; start <= N; ++start)
    {
        if (visited[start]) continue;

        pq.push({start, 0});

        while (!pq.empty())
        {
            std::pair<int, int> node = pq.top();
            pq.pop();

            if (visited[node.first]) continue;

            visited[node.first] = true;
            total_cost += node.second;

            for (auto next_node : graphs[node.first])
            {
                if (visited[next_node.first]) continue;
                pq.push({next_node.first, next_node.second});
            }
        }
    }

    std::cout << total_cost << '\n';

    return 0;
}
