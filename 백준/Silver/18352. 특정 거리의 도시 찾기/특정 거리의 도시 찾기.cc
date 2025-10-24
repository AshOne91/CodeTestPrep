#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;
const int INF = std::numeric_limits<int>::max();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K, X;
    cin >> N >> M >> K >> X;  // N=도시, M=도로, K=목표거리, X=출발도시

    vector<vector<int>> graphs(N + 1);
    vector<int> dist(N + 1, INF);

    for (int i = 0; i < M; ++i) {
        int from, to;
        cin >> from >> to;
        graphs[from].push_back(to);
    }

    queue<int> qu;
    qu.push(X);      // ✅ 출발 도시는 X
    dist[X] = 0;
    vector<int> result;

    while (!qu.empty()) {
        int node = qu.front();
        qu.pop();

        if (dist[node] == K) {   // ✅ 목표 거리가 K
            result.push_back(node);
            continue;
        }

        for (int next_node : graphs[node]) {
            int next_dist = dist[node] + 1;
            if (next_dist > K || dist[next_node] != INF)
                continue;
            dist[next_node] = next_dist;
            qu.push(next_node);
        }
    }

    if (result.empty()) {
        cout << -1 << '\n';
    } else {
        sort(result.begin(), result.end());
        for (auto node : result)
            cout << node << '\n';
    }

    return 0;
}
