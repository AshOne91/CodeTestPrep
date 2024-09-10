#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
int maxSheep = 0;

struct State {
    int node;               // 현재 위치한 노드
    int sheep;              // 현재까지 모은 양의 수
    int wolf;               // 현재까지 모은 늑대의 수
    vector<int> nextNodes;  // 앞으로 방문할 수 있는 노드들
};

void bfs(const vector<int>& info) {
    queue<State> q;
    q.push({0, 1, 0, graph[0]});  // 시작은 루트에서, 양은 1마리

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        // 최대 양의 수 갱신
        maxSheep = max(maxSheep, cur.sheep);

        // 가능한 다음 노드들을 탐색
        for (int i = 0; i < cur.nextNodes.size(); i++) {
            int nextNode = cur.nextNodes[i];

            // 새로운 양과 늑대의 수 계산
            int newSheep = cur.sheep + (info[nextNode] == 0 ? 1 : 0);
            int newWolf = cur.wolf + (info[nextNode] == 1 ? 1 : 0);

            // 늑대의 수가 양보다 많아지면 그 경로는 무시
            if (newWolf >= newSheep) continue;

            // 새로운 상태에서 갈 수 있는 노드 리스트 갱신
            vector<int> newNextNodes = cur.nextNodes;
            newNextNodes.erase(newNextNodes.begin() + i);  // 현재 방문한 노드 제거
            for (int child : graph[nextNode]) {
                newNextNodes.push_back(child);  // 새로운 자식 노드 추가
            }

            // 새로운 상태를 큐에 추가
            q.push({nextNode, newSheep, newWolf, newNextNodes});
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int n = info.size();
    graph.assign(n, vector<int>());

    // 그래프 구성
    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
    }

    // BFS 탐색 시작
    bfs(info);

    return maxSheep;
}