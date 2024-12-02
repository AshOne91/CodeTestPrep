#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // 무한대를 표현

// 다익스트라 알고리즘 함수
int dijkstra(int start, int end, const vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INF); // 최단 거리 배열 초기화
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // 최소 힙 사용

    dist[start] = 0;            // 시작 정점까지의 거리는 0
    pq.push({0, start});        // (거리, 정점) 형태로 힙에 추가

    while (!pq.empty()) {
        int current_dist = pq.top().first; // 현재 정점까지의 거리
        int current = pq.top().second;    // 현재 정점
        pq.pop();

        // 이미 처리된 거리라면 무시
        if (current_dist > dist[current]) continue;

        // 인접 정점 탐색
        for (const auto& neighbor : graph[current]) {
            int next = neighbor.first;     // 인접 정점
            int weight = neighbor.second;  // 가중치

            // 더 짧은 경로가 발견되었을 경우
            if (dist[current] + weight < dist[next]) {
                dist[next] = dist[current] + weight; // 최단 거리 갱신
                pq.push({dist[next], next});        // 힙에 새로운 경로 추가
            }
        }
    }

    return dist[end]; // 최종적으로 도착 정점까지의 거리 반환
}

int main() {
    int N, M; // 도시 개수와 버스 개수
    cin >> N >> M;

    // 그래프 입력을 위한 인접 리스트 초기화
    vector<vector<pair<int, int>>> graph(N + 1); // 1-indexed 그래프

    // 버스 정보 입력
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w); // 출발 도시 u에서 도착 도시 v로 가는 비용 w
    }

    // 출발점과 도착점 입력
    int start, end;
    cin >> start >> end;

    // 다익스트라 알고리즘 실행
    int result = dijkstra(start, end, graph);

    // 결과 출력
    cout << result << endl;

    return 0;
}
