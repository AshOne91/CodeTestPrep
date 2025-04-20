#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, K;
    std::cin >> N >> K;

    // 거리 배열 초기화
    std::vector<int> dist(100001, INF);
    dist[N] = 0;

    // 비용 기준 오름차순 우선순위 큐
    auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);

    // 시작 노드
    pq.push({N, 0});

    while (!pq.empty()) {
        auto [current, cost] = pq.top();
        pq.pop();

        // 이미 더 짧은 거리로 방문했으면 스킵
        if (cost > dist[current]) continue;

        // 목표 도달 시
        if (current == K) {
            std::cout << cost;
            return 0;
        }

        // 순간이동 (가중치 0)
        int next = current * 2;
        if (next <= 100000 && dist[next] > cost) {
            dist[next] = cost;
            pq.push({next, cost});
        }

        // 걷기 (가중치 1)
        next = current - 1;
        if (next >= 0 && dist[next] > cost + 1) {
            dist[next] = cost + 1;
            pq.push({next, cost + 1});
        }

        next = current + 1;
        if (next <= 100000 && dist[next] > cost + 1) {
            dist[next] = cost + 1;
            pq.push({next, cost + 1});
        }
    }

    return 0;
}
