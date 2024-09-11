#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <functional>

using namespace std;

const int INF = numeric_limits<int>::max(); // 무한대를 표현하기 위한 값

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    vector<vector<pair<int, int>>> graphs(N + 1); // 그래프 표현, 1부터 시작하므로 N+1 크기
    vector<int> dist(N + 1, INF); // 최단 거리를 저장하는 배열

    // 그래프 생성 (양방향)
    for (auto& edge : road) {
        graphs[edge[0]].push_back({edge[1], edge[2]});
        graphs[edge[1]].push_back({edge[0], edge[2]});
    }

    // 다익스트라 알고리즘 실행
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1}); // {최단 거리, 시작 노드}
    dist[1] = 0;

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // 이미 처리된 거리보다 크면 무시
        if (current_dist > dist[node]) continue;

        // 인접한 노드들을 확인
        for (const auto& edge : graphs[node]) {
            int nextNode = edge.first;
            int weight = edge.second;

            // 더 짧은 경로를 찾으면 업데이트
            if (dist[node] + weight < dist[nextNode]) {
                dist[nextNode] = dist[node] + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    // 최단 거리가 K 이하인 마을의 개수 세기
    for (int i = 1; i <= N; ++i) {
        if (dist[i] <= K) {
            ++answer;
        }
    }

    return answer;
}