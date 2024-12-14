#include <iostream>
#include <vector>
#include <cstring>

const int MAX = 10001; // 최대 노드 수
std::vector<std::pair<int, int>> graph[MAX];
bool visited[MAX];
int max_dist = 0;
int farthest_node = 0;

// DFS 함수: 현재 노드와 거리 합계를 입력받아 탐색
void dfs(int node, int dist) {
    visited[node] = true;

    if (dist > max_dist) {
        max_dist = dist;
        farthest_node = node;
    }

    for (auto &edge : graph[node]) {
        int next_node = edge.first;
        int weight = edge.second;
        if (!visited[next_node]) {
            dfs(next_node, dist + weight);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int parent, child, weight;
        std::cin >> parent >> child >> weight;
        graph[parent].emplace_back(child, weight);
        graph[child].emplace_back(parent, weight);
    }

    // 1. 루트에서 가장 먼 노드(A)를 찾기 위한 첫 번째 DFS
    memset(visited, false, sizeof(visited));
    dfs(1, 0);

    // 2. A에서 가장 먼 노드(B)를 찾기 위한 두 번째 DFS
    memset(visited, false, sizeof(visited));
    max_dist = 0;
    dfs(farthest_node, 0);

    // 트리의 지름 출력
    std::cout << max_dist << '\n';

    return 0;
}
